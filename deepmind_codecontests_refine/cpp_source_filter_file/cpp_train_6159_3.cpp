#include <bits/stdc++.h>
using namespace std;
char c[1005], s[55], t[55];
int prefix1[1005], prefix2[1005];
int dp[1005][55][55];
bool vis[1005][55][55];
void getPrefix1(int m) {
  int i = 1, j = 0;
  while (i < m) {
    if (s[i] == s[j]) {
      prefix1[i++] = (++j);
    } else {
      if (j != 0)
        j = prefix1[j - 1];
      else
        i++;
    }
  }
}
void getPrefix2(int m) {
  int i = 1, j = 0;
  while (i < m) {
    if (t[i] == t[j]) {
      prefix2[i++] = (++j);
    } else {
      if (j != 0)
        j = prefix2[j - 1];
      else
        i++;
    }
  }
}
int main() {
  scanf("%s%s%s", c, s, t);
  int n = strlen(c), m1 = strlen(s), m2 = strlen(t);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m1; j++)
      for (int k = 0; k < m2; k++) dp[i][j][k] = -1e9;
  getPrefix1(m1);
  getPrefix2(m2);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      int j = 0, k = 0;
      if (c[i] == '*') {
        for (int x = 'a'; x <= 'z'; x++) {
          int pj = j, pk = k, nj = j, nk = k, val = 0;
          while (s[pj] != x && pj != 0) pj = prefix1[pj - 1];
          while (t[pk] != x && pk != 0) pk = prefix2[pk - 1];
          nj = pj, nk = pk;
          if (s[pj] == x && t[pk] == x) {
            nj = pj + 1, nk = pk + 1;
            if (nj == m1) val++, nj = prefix1[nj - 1];
            if (nk == m2) val--, nk = prefix2[nk - 1];
          } else if (s[pj] == x) {
            nj = pj + 1;
            if (nj == m1) val++, nj = prefix1[nj - 1];
          } else if (t[pk] == x) {
            nk = pk + 1;
            if (nk == m2) val--, nk = prefix1[nk - 1];
          }
          dp[i][nj][nk] = max(dp[i][nj][nk], val);
          vis[i][nj][nk] = 1;
        }
      } else {
        int pj = j, pk = k, nj = j, nk = k, val = 0;
        char x = c[i];
        while (s[pj] != x && pj != 0) pj = prefix1[pj - 1];
        while (t[pk] != x && pk != 0) pk = prefix2[pk - 1];
        nj = pj, nk = pk;
        if (s[pj] == x && t[pk] == x) {
          nj = pj + 1, nk = pk + 1;
          if (nj == m1) val++, nj = prefix1[nj - 1];
          if (nk == m2) val--, nk = prefix2[nk - 1];
        } else if (s[pj] == x) {
          nj = pj + 1;
          if (nj == m1) val++, nj = prefix1[nj - 1];
        } else if (t[pk] == x) {
          nk = pk + 1;
          if (nk == m2) val--, nk = prefix1[nk - 1];
        }
        dp[i][nj][nk] = max(dp[i][nj][nk], val);
        vis[i][nj][nk] = 1;
      }
    } else {
      for (int j = 0; j < m1; j++) {
        for (int k = 0; k < m2; k++) {
          if (!vis[i - 1][j][k]) continue;
          if (c[i] == '*') {
            for (int x = 'a'; x <= 'z'; x++) {
              int pj = j, pk = k, nj = j, nk = k, val = dp[i - 1][j][k];
              while (s[pj] != x && pj != 0) pj = prefix1[pj - 1];
              while (t[pk] != x && pk != 0) pk = prefix2[pk - 1];
              nj = pj, nk = pk;
              if (s[pj] == x && t[pk] == x) {
                nj = pj + 1, nk = pk + 1;
                if (nj == m1) val++, nj = prefix1[nj - 1];
                if (nk == m2) val--, nk = prefix2[nk - 1];
              } else if (s[pj] == x) {
                nj = pj + 1;
                if (nj == m1) val++, nj = prefix1[nj - 1];
              } else if (t[pk] == x) {
                nk = pk + 1;
                if (nk == m2) val--, nk = prefix1[nk - 1];
              }
              dp[i][nj][nk] = max(dp[i][nj][nk], val);
              vis[i][nj][nk] = 1;
            }
          } else {
            int pj = j, pk = k, nj = j, nk = k, val = dp[i - 1][j][k];
            char x = c[i];
            while (s[pj] != x && pj != 0) pj = prefix1[pj - 1];
            while (t[pk] != x && pk != 0) pk = prefix2[pk - 1];
            nj = pj, nk = pk;
            if (s[pj] == x && t[pk] == x) {
              nj = pj + 1, nk = pk + 1;
              if (nj == m1) val++, nj = prefix1[nj - 1];
              if (nk == m2) val--, nk = prefix2[nk - 1];
            } else if (s[pj] == x) {
              nj = pj + 1;
              if (nj == m1) val++, nj = prefix1[nj - 1];
            } else if (t[pk] == x) {
              nk = pk + 1;
              if (nk == m2) val--, nk = prefix1[nk - 1];
            }
            dp[i][nj][nk] = max(dp[i][nj][nk], val);
            vis[i][nj][nk] = 1;
          }
        }
      }
    }
  }
  int ans = -1e9;
  for (int j = 0; j < m1; j++) {
    for (int k = 0; k < m2; k++) {
      ans = max(ans, dp[n - 1][j][k]);
    }
  }
  printf("%d\n", ans);
}
