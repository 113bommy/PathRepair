#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
const int K = 501;
int n, m, k, x[K], y[K];
int sum[K << 2][K << 2];
vector<int> X, Y;
void build() {
  for (int i = 1; i < X.size(); i++)
    for (int j = 1; j < Y.size(); j++) sum[i][j] += sum[i][j - 1];
  for (int j = 1; j < Y.size(); j++)
    for (int i = 1; i < X.size(); i++) sum[i][j] += sum[i - 1][j];
}
void add(int x, int y, int vx, int vy) {
  sum[x][y]++;
  sum[x][vy + 1]--;
  sum[vx + 1][y]--;
  sum[vx + 1][vy + 1]++;
}
void print() {
  for (int i = 1; i < X.size(); i++)
    for (int j = 1; j < Y.size(); j++)
      cout << sum[i][j] << " \n"[j == Y.size() - 1];
}
bool can(int d) {
  int lx = oo, ly = oo, hx = -1, hy = -1;
  for (int i = 1; i < X.size(); i++)
    for (int j = 1; j < Y.size(); j++)
      if (!sum[i][j]) {
        lx = min(lx, X[i - 1]);
        ly = min(ly, Y[j - 1]);
        hx = max(hx, X[i]);
        hy = max(hy, Y[j]);
      }
  return hx - lx <= 2 * d + 1 && hy - ly <= 2 * d + 1;
}
void print(vector<int> vec) {
  for (auto x : vec) cout << x << ' ';
  cout << endl;
}
bool ok(int d) {
  memset(sum, 0, sizeof sum);
  X.clear();
  Y.clear();
  X.push_back(0);
  X.push_back(n);
  Y.push_back(0);
  Y.push_back(m);
  for (int i = 0; i < k; i++) {
    X.push_back(max(0, x[i] - d - 1));
    Y.push_back(max(0, y[i] - d - 1));
    X.push_back(min(n, x[i] + d));
    Y.push_back(min(m, y[i] + d));
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  X.resize(unique(X.begin(), X.end()) - X.begin());
  Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
  for (int i = 0; i < k; i++) {
    int rx =
        lower_bound(X.begin(), X.end(), max(0, x[i] - d - 1)) - X.begin() + 1;
    int ry =
        lower_bound(Y.begin(), Y.end(), max(0, y[i] - d - 1)) - Y.begin() + 1;
    int rvx = lower_bound(X.begin(), X.end(), min(n, x[i] + d)) - X.begin();
    int rvy = lower_bound(Y.begin(), Y.end(), min(m, y[i] + d)) - Y.begin();
    add(rx, ry, rvx, rvy);
  }
  build();
  return can(d);
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) cin >> x[i] >> y[i];
  int lo = 0, hi = oo;
  while (lo < hi) {
    int mid = lo + hi >> 1;
    if (ok(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << hi << endl;
}
