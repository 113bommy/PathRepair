#include <bits/stdc++.h>
using namespace std;
int n, m;
char ans[1000100];
int vis[1000100];
char p[1000100];
int pre[1000100];
int l;
int ma[1000100];
int mat[1000100];
int mmin;
bool scan_d(int &num) {
  char in;
  bool IsN = false;
  in = getchar();
  if (in == EOF) return false;
  while (in != '-' && (in < '0' || in > '9')) {
    if (in == EOF) return false;
    in = getchar();
  }
  if (in == '-') {
    IsN = true;
    num = 0;
  } else
    num = in - '0';
  while (in = getchar(), in >= '0' && in <= '9') {
    num *= 10, num += in - '0';
  }
  if (IsN) num = -num;
  return true;
}
bool cptpf(int prefix[], char p[], int len) {
  int lolp = 0;
  prefix[0] = prefix[1] = 0;
  int nocm = 2;
  for (nocm = 2; nocm < len + 1; nocm++) {
    while (lolp > 0 && p[lolp] != p[nocm - 1]) lolp = prefix[lolp];
    if (p[lolp] == p[nocm - 1]) lolp++;
    prefix[nocm] = lolp;
    if (vis[nocm + mmin - 1]) {
      if (nocm == l || lolp == l)
        ;
      else if (lolp < l)
        return false;
      else {
        int rt = lolp;
        int flag = 0;
        while (rt > l) {
          rt = prefix[rt];
          if (vis[rt + mmin - 1]) {
            flag = 1;
            break;
          }
        }
        if (flag)
          ;
        else if (rt < l)
          return false;
      }
    }
  }
  return true;
}
int main() {
  int i, j;
  while (~scanf("%d%d", &n, &m)) {
    scanf("%s", p);
    if (m == 0) {
      long long w = 1;
      for (i = 0; i < n; i++) {
        w *= 26;
        w %= 1000000007;
      }
      printf("%I64d\n", w);
      continue;
    }
    memset(ans, '0', sizeof(ans));
    memset(vis, 0, sizeof(vis));
    l = strlen(p);
    mmin = 0x3f3f3f3f;
    for (i = 1; i <= m; i++) {
      scan_d(ma[i]);
      if (mmin > ma[i]) mmin = ma[i];
      mat[i] = ma[i] + l - 2;
    }
    sort(mat + 1, mat + m + 1);
    for (i = 1; i <= m; i++) {
      int tr = mat[i];
      while (tr >= mat[i] - l + 1 && ans[tr] == '0') {
        ans[tr] = p[tr + l - mat[i] - 1];
        tr--;
      }
    }
    for (i = 1; i <= m; i++) vis[mat[i] + 1] = 1;
    int re = cptpf(pre, ans + mmin - 1, n - mmin + 1);
    if (re == false) {
      printf("0\n");
      continue;
    }
    long long w = 1;
    for (i = 0; i < n; i++) {
      if (ans[i] == '0') {
        w *= 26;
        w %= 1000000007;
      }
    }
    printf("%I64d\n", w);
  }
  return 0;
}
