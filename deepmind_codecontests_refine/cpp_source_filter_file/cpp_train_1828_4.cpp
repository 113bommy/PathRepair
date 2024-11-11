#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const long long INF = 1e17;
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;
struct List {
  int data, d[4];
};
vector<List> work;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, q;
inline bool check(int x, int y) {
  return x >= 0 && x < n + 2 && y >= 0 && y < n + 2;
}
inline int toNum(int x, int y) { return x * (m + 2) + y; }
inline int find(int x, int y) {
  int now = 0;
  while (x--) {
    now = work[now].d[DOWN];
  }
  while (y--) {
    now = work[now].d[RIGHT];
  }
  return now;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> q;
  work.resize((n + 2) * (m + 2));
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < m + 2; j++) {
      for (int t = 0; t < 4; t++) {
        int nx = i + dx[t], ny = j + dy[t];
        if (check(nx, ny)) {
          work[toNum(i, j)].d[t] = toNum(nx, ny);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> work[toNum(i, j)].data;
    }
  }
  while (q--) {
    int a, b, c, d, h, w;
    cin >> a >> b >> c >> d >> h >> w;
    int nowa = find(a, b), nowb = find(c, d);
    for (int t = 0; t < 4; t++) {
      for (int i = 0; i < (t % 2 == 0 ? w : h); i++) {
        swap(work[nowa].d[t], work[nowb].d[t]);
        swap(work[work[nowa].d[t]].d[(t + 2) % 4],
             work[work[nowb].d[t]].d[(t + 2) % 4]);
        if (i + 1 != (t % 2 == 0 ? w : h)) {
          nowa = work[nowa].d[(t + 1) % 4];
          nowb = work[nowb].d[(t + 1) % 4];
        }
      }
    }
  }
  int firstCol = find(1, 1);
  for (int i = 0; i < n; i++) {
    int now = firstCol;
    for (int j = 0; j < m; j++) {
      cout << work[now].data << " ";
      now = work[now].d[RIGHT];
    }
    cout << "\n";
    firstCol = work[firstCol].d[DOWN];
  }
  return 0;
}
