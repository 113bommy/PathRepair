#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
char t[MAXN], s[MAXN];
int m, l, n;
int pch1[MAXN], pch2[MAXN], par1[MAXN], par2[MAXN], t1[MAXN][26], t2[MAXN][26],
    cnt1[MAXN], cnt2[MAXN];
int go1[MAXN][26], go2[MAXN][26], fail1[MAXN], fail2[MAXN], dp1[MAXN],
    dp2[MAXN];
int Go1(int v, int c);
int get_fail1(int v) {
  if (fail1[v] == -1) {
    if (v == 0 || par1[v] == 0)
      fail1[v] = 0;
    else
      fail1[v] = Go1(get_fail1(par1[v]), pch1[v]);
  }
  return fail1[v];
}
int Go1(int v, int c) {
  if (go1[v][c] == -1) {
    if (t1[v][c] != -1)
      go1[v][c] = t1[v][c];
    else
      go1[v][c] = v == 0 ? 0 : Go1(get_fail1(v), c);
  }
  return go1[v][c];
}
int calc1(int v) {
  if (dp1[v] != -1) return dp1[v];
  if (v == 0) return 0;
  return dp1[v] = calc1(get_fail1(v)) + cnt1[v];
}
int Go2(int v, int c);
int get_fail2(int v) {
  if (fail2[v] == -1) {
    if (v == 0 || par2[v] == 0)
      fail2[v] = 0;
    else
      fail2[v] = Go2(get_fail2(par2[v]), pch2[v]);
  }
  return fail2[v];
}
int Go2(int v, int c) {
  if (go2[v][c] == -1) {
    if (t2[v][c] != -1)
      go2[v][c] = t2[v][c];
    else
      go2[v][c] = v == 0 ? 0 : Go2(get_fail2(v), c);
  }
  return go2[v][c];
}
int calc2(int v) {
  if (dp2[v] != -1) return dp2[v];
  if (v == 0) return 0;
  return dp2[v] = calc2(get_fail2(v)) + cnt2[v];
}
int A[MAXN], B[MAXN];
int main() {
  scanf("%s", t);
  m = strlen(t);
  int N1 = 1;
  int N2 = 1;
  memset(t1, -1, sizeof t1);
  memset(t2, -1, sizeof t2);
  memset(fail1, -1, sizeof fail1);
  memset(fail2, -1, sizeof fail2);
  memset(go1, -1, sizeof go1);
  memset(go2, -1, sizeof go2);
  memset(dp1, -1, sizeof dp1);
  memset(dp2, -1, sizeof dp2);
  scanf("%d", &n);
  while (n--) {
    scanf(" %s", s);
    l = strlen(s);
    int cur = 0;
    for (int i = 0; i < l; i++) {
      if (t1[cur][s[i] - 'a'] == -1) {
        t1[cur][s[i] - 'a'] = N1;
        par1[N1] = cur;
        pch1[N1] = s[i] - 'a';
        N1++;
      }
      cur = t1[cur][s[i] - 'a'];
    }
    cnt1[cur]++;
    cur = 0;
    for (int i = l - 1; i >= 0; i--) {
      if (t2[cur][s[i] - 'a'] == -1) {
        t2[cur][s[i] - 'a'] = N2;
        par2[N2] = cur;
        pch2[N2] = s[i] - 'a';
        N2++;
      }
      cur = t2[cur][s[i] - 'a'];
    }
    cnt2[cur]++;
  }
  int cur = 0;
  for (int i = 0; i < m; i++) {
    cur = Go1(cur, t[i] - 'a');
    A[i] = calc1(cur);
  }
  cur = 0;
  for (int i = m - 1; i >= 0; i--) {
    cur = Go2(cur, t[i] - 'a');
    B[i] = calc2(cur);
  }
  long long res = 0;
  for (int i = 0; i + 1 < m; i++) res += 1LL * A[i] * B[i + 1];
  printf("%I64d\n", res);
  return 0;
}
