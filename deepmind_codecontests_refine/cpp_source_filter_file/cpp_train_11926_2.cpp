#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const int maxn = 2020;
int n, m, k;
int q;
long long g[maxn][maxn];
void update(int i, int _j, long long dx) {
  while (i <= n) {
    int j = _j;
    while (j <= m) {
      g[i][j] += dx;
      j += j & -j;
    }
    i += i & -i;
  }
}
long long get(int i, int _j) {
  long long res = 0;
  while (i > 0) {
    int j = _j;
    while (j > 0) {
      res += g[i][j];
      j -= j & -j;
    }
    i -= i & -i;
  }
  return res;
}
struct node {
  int i, j;
  long long w;
};
vector<node> gar[maxn];
int state[maxn], edit[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    int len;
    cin >> len;
    while (len--) {
      int x, y, w;
      cin >> x >> y >> w;
      gar[i].push_back({x, y, w});
    }
    state[i] = edit[i] = 1;
  }
  cin >> q;
  while (q--) {
    string z;
    cin >> z;
    if (z[0] == 'S') {
      int idx;
      cin >> idx;
      state[idx] ^= 1;
      edit[idx] ^= 1;
    } else {
      for (int i = 1; i <= m; i++) {
        if (edit[i]) {
          if (state[i]) {
            for (auto p : gar[i]) {
              update(p.i, p.j, p.w);
            }
          } else {
            for (auto p : gar[i]) {
              update(p.i, p.j, -p.w);
            }
          }
          edit[i] = 0;
        }
      }
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      long long res =
          get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) + get(x1 - 1, y1 - 1);
      cout << res << "\n";
    }
  }
  return 0;
}
