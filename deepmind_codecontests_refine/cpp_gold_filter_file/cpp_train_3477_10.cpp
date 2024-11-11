#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
struct seg {
  int a, b, ta, tb;
};
int mp[105][3], r;
int cc[200][110];
int gd(int s1, int s2, int e1, int e2, int len) {
  int mask = (s1 << 3) + (s2 << 2) + (e1 << 1) + e2;
  if (cc[mask][len] != -1) return cc[mask][len];
  int a[111][5] = {0};
  a[1][1] = s1;
  a[1][2] = s2;
  a[len][1] = e1;
  a[len][2] = e2;
  set<int> ss;
  bool alive[111];
  for (int i = 1; i <= len; i++)
    for (int j = 1; j <= 2; j++)
      if (a[i][j] == 0) {
        a[i][j]++;
        a[i - 1][3 - j]++;
        a[i][3 - j]++;
        a[i + 1][3 - j]++;
        for (int q = 1; q <= len; q++) alive[q] = (a[q][1] * a[q][2] == 0);
        int st = 1, res = 0;
        while (st <= len) {
          while (st <= len && !alive[st]) st++;
          if (st > len) break;
          int fin = st;
          while (fin + 1 <= len && alive[fin + 1]) fin++;
          res ^= gd(a[st][1], a[st][2], a[fin][1], a[fin][2], fin - st + 1);
          st = fin + 1;
        }
        ss.insert(res);
        a[i][j]--;
        a[i - 1][3 - j]--;
        a[i][3 - j]--;
        a[i + 1][3 - j]--;
      }
  int i = 0;
  for (int x : ss)
    if (i != x)
      break;
    else
      i++;
  return cc[mask][len] = i;
}
int main() {
  scanf("%d%d", &r, &n);
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    int u, v;
    cin >> u >> v;
    mp[u][v] = 1;
    mp[u - 1][3 - v] = 1;
    mp[u][3 - v] = 1;
    mp[u + 1][3 - v] = 1;
  }
  int ans = 0;
  memset(cc, -1, sizeof cc);
  n = r;
  for (int st = 1; st <= n;) {
    while (st <= n && mp[st][1] * mp[st][2] != 0) st++;
    if (st > n) break;
    int f = st;
    while (f + 1 <= n && mp[f + 1][1] * mp[f + 1][2] == 0) f++;
    ans ^= gd(mp[st][1], mp[st][2], mp[f][1], mp[f][2], f - st + 1);
    st = f + 1;
  }
  puts(ans > 0 ? "WIN" : "LOSE");
  return 0;
}
