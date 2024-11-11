#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
const long long int INF = 2e18;
int used[26], with[26][26];
bool dfs(int id, int n) {
  used[id] = 1;
  for (int i = 0; i < n; i++) {
    if (with[id][i]) {
      if (used[i] == 1) return false;
      if (!used[i]) dfs(i, n);
    }
  }
  used[id] = 2;
  return true;
}
long long int dp[1 << 16], up[1 << 16];
int can[18][1 << 16];
long long int cnt[1 << 16];
int c1[18], c2[18];
int ch[18], re_ch[18];
void got_it(int n, int allready) {
  memset(dp, 0, sizeof dp);
  int tz = 0;
  int tete[19];
  for (int i = n - 1; i >= 0; i--) {
    if (ch[i] == -1) tete[tz++] = i;
  }
  for (int i = 0; i < n; i++) {
    if (ch[i] == -1) {
      int m1 = 0, m2 = (1 << allready) - 1;
      c1[i] = 0;
      c2[i] = 0;
      for (int j = 0; j < allready; j++) {
        if (re_ch[j] > i) {
          for (int k = allready; k < n; k++) {
            if (with[j][k]) m1 = (m1 ^ (1 << k));
          }
        } else
          m2 = (m2 ^ (1 << j));
      }
      c1[i] = m1;
      c2[i] = m2;
    }
  }
  dp[(1 << n) - 1] = 1;
  for (int j = (1LL << n) - 1; j >= 0; j--) {
    int kol = 0;
    if ((j & ((1 << allready) - 1)) != ((1 << allready) - 1)) continue;
    for (int i = allready; i < n; i++) {
      if (j & (1 << i)) kol++;
    }
    if ((!kol)) continue;
    kol--;
    kol = tete[tz - 1 - kol];
    int m1 = c1[kol];
    int m2 = (j ^ c2[kol]);
    for (int i = allready; i < n; i++) {
      if (m1 & (1 << i)) continue;
      if ((m2 & (1 << i)) && !can[i][m2 ^ (1 << i)]) {
        dp[j ^ (1 << i)] = min(INF, dp[j ^ (1 << i)] + dp[j]);
      }
    }
  }
  memset(up, 0, sizeof up);
  memset(cnt, 0, sizeof cnt);
  cnt[0] = dp[(1 << (allready + 1)) - 1];
  for (int j = allready; j < n; j++) {
    up[((1 << (allready)) - 1) | (1 << j)] = 1;
  }
  for (int j = 0; j < (1 << n); j++) {
    if ((j & ((1 << allready) - 1)) != ((1 << allready) - 1)) continue;
    if (j & (1 << allready)) continue;
    int kol = 0;
    for (int i = allready; i < n; i++) {
      if (j & (1 << i)) kol++;
    }
    if (!kol) continue;
    int nm = tete[kol];
    int m1 = c1[nm];
    int m2 = (j ^ c2[nm]);
    cnt[kol] = min(INF, cnt[kol] + (up[j] * dp[j | (1 << allready)]));
    for (int i = allready; i < n; i++) {
      if (m1 & (1 << i)) continue;
      if (!(m2 & (1 << i)) && !can[i][m2]) {
        up[j | (1 << i)] = min(INF, up[j | (1 << i)] + up[j]);
      }
    }
  }
}
int main() {
  long long int n, y, m;
  cin >> n >> y >> m;
  memset(used, 0, sizeof used);
  memset(with, 0, sizeof with);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    with[a][b]++;
  }
  memset(can, 0, sizeof can);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        cnt[i]++;
        continue;
      }
      for (int k = 0; k < n; k++) {
        if ((i & (1 << k)) && with[j][k]) {
          can[j][i]++;
        }
      }
    }
  }
  memset(used, 0, sizeof used);
  for (int i = 0; i < n; i++) {
    if (!used[i] && !dfs(i, n)) {
      cout << "The times have changed";
      return 0;
    }
  }
  memset(ch, -1, sizeof ch);
  memset(re_ch, -1, sizeof re_ch);
  y -= 2000;
  got_it(n, 0);
  if (dp[0] < y) {
    cout << "The times have changed";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    got_it(n, i);
    int nx = 0;
    for (int j = 0; j < n; j++) {
      if (ch[j] != -1) continue;
      ch[j] = i;
      re_ch[i] = j;
      long long int val = cnt[nx++];
      if (val >= y) {
        break;
      }
      y -= val;
      ch[j] = -1;
      re_ch[i] = -1;
    }
  }
  for (int i = 0; i < n; i++) cout << re_ch[i] + 1 << " ";
}
