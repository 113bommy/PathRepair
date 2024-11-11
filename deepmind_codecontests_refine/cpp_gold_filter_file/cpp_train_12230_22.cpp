#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void umax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void umin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
const int inf = 1e9 + 143;
const long long longinf = 1e18 + 143;
inline int read() {
  int x;
  scanf(" %d", &x);
  return x;
}
const int N = 111;
int lson[N][N];
int rson[N][N];
int g[N][N];
vector<int> ans;
void calc(int l, int r) {
  if (l > r) return;
  if (l == r) {
    ans.push_back(l);
    return;
  }
  int root = l;
  for (int m = l; m <= r; m++) {
    bool ok = true;
    for (int i = l + 1; i <= m; i++) {
      if (rson[root][i]) ok = false;
      for (int j = m + 1; j <= r; j++) {
        if (g[i][j]) {
          ok = false;
          break;
        }
      }
    }
    for (int i = m + 1; i <= r; i++) {
      if (lson[root][i]) ok = false;
    }
    if (ok) {
      calc(l + 1, m);
      ans.push_back(l);
      calc(m + 1, r);
      return;
    }
  }
}
int main() {
  int n = read();
  int m = read();
  char foo[32];
  for (int i = 0; i < m; i++) {
    int a = read();
    int b = read();
    if (a >= b) {
      puts("IMPOSSIBLE");
      return 0;
    }
    scanf(" %s", foo);
    g[a][b] = 1;
    if (foo[0] == 'L') {
      lson[a][b] = 1;
    } else {
      rson[a][b] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      for (int k = 1; k <= n; k++) {
        if (j == k || i == k) continue;
        g[j][k] |= (g[j][i] && g[i][k]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (lson[i][j]) {
        for (int k = 1; k <= n; k++) {
          if (k != i && k != j && g[j][k]) {
            lson[i][k] = 1;
          }
        }
      }
      if (rson[i][j]) {
        for (int k = 1; k <= n; k++) {
          if (k != i && k != j && g[j][k]) {
            rson[i][k] = 1;
          }
        }
      }
    }
  }
  calc(1, n);
  if (ans.size() != n) {
    puts("IMPOSSIBLE");
  } else {
    for (int i = 0; i < n; i++) {
      printf("%d ", ans[i]);
    }
  }
  return 0;
}
