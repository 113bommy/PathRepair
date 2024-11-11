#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 200500;
struct pt {
  int x, y, l;
  pt(int x, int y) : x(x), y(y) { l = max(x, y); }
  pt() {}
  long long dist(pt other) { return abs(x - other.x) + abs(y - other.y); }
};
pt p[N];
map<int, vector<int>> m;
int w[N][2], x[N], y[N];
bool cmp(int i, int j) {
  if (x[i] == x[j]) return y[i] < y[j];
  return x[i] < x[j];
}
map<int, int> z;
vector<int> l;
long long dp[N][2];
int get(int i, int j) { return w[i][j]; }
long long dist(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }
long long f(int i, bool b) {
  if (i == ((int)(l).size()) - 1) return dist(get(i, b), get(i, !b));
  if (dp[i][b] != -1) return dp[i][b];
  long long r = 1LL << 50;
  long long d = dist(get(i, b), get(i, !b));
  r = min(r, d + dist(get(i + 1, 0), get(i, !b)) + f(i + 1, 0));
  r = min(r, d + dist(get(i + 1, 1), get(i, !b)) + f(i + 1, 1));
  return dp[i][b] = r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n;
  l.push_back(0);
  n++;
  for (int i = 1, ThxDem = n; i < ThxDem; ++i)
    cin >> x[i] >> y[i], l.push_back(max(x[i], y[i]));
  sort(l.begin(), l.end());
  l.resize(distance(l.begin(), unique(l.begin(), l.end())));
  for (int i = 0, ThxDem = ((int)(l).size()); i < ThxDem; ++i) z[l[i]] = i;
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    m[z[max(x[i], y[i])]].push_back(i);
  for (int i = 0, ThxDem = ((int)(l).size()); i < ThxDem; ++i) {
    sort(m[i].begin(), m[i].end(), cmp);
    w[i][0] = m[i][0];
    w[i][1] = m[i].back();
  }
  cout << f(0, 0) << "\n";
}
