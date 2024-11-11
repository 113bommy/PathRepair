#include <bits/stdc++.h>
using namespace std;
int n, ans = 10;
string s;
bool e[55][55], g[55][55];
bool q[55];
bool bit(int mask, int x) {
  mask = mask & (1 << x);
  return (mask > 0);
}
int get(char q) {
  if (q == 'R')
    return 0;
  else if (q == 'G')
    return 1;
  else if (q == 'W')
    return 2;
  else if (q == 'Y')
    return 3;
  else
    return 4;
}
int main() {
  cin >> n;
  int sz = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    int u, v;
    u = get(s[0]);
    v = s[1] - '1';
    if (!g[u][v]) sz++;
    g[u][v] = true;
  }
  if (sz == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int mask = 0; mask < (1 << 10); ++mask) {
    for (int j = 0; j < 10; ++j) q[j] = bit(mask, j);
    int res = 0;
    for (int i = 0; i < 10; ++i) res += q[i];
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 5; ++j)
        if (g[i][j]) {
          for (int x = 0; x < 5; ++x)
            for (int y = 0; y < 5; ++y) {
              if (!g[x][y]) continue;
              if (x == i && y == j) continue;
              if (x != i) {
                if (q[x] || q[i]) continue;
              }
              if (y != j) {
                if (q[y + 5] || q[j + 5]) continue;
              }
              res = 10;
              break;
            }
        }
    if (res < ans) ans = res;
  }
  cout << ans << endl;
  return 0;
}
