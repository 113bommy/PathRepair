#include <bits/stdc++.h>
char str[2100];
int f[2100], n, m;
int dp[2100][2100];
void getF() {
  for (int i = 0; i < n;) {
    if (str[i] >= '0' && str[i] <= '9') {
      f[m++] = 0;
      while (i + 1 < n && str[i + 1] >= '0' && str[i + 1] <= '9') ++i;
    } else if (str[i] == '+' || str[i] == '-')
      f[m++] = 1;
    else
      f[m++] = 2;
    ++i;
  }
}
bool ok() {
  for (int i = 0; i < m; ++i)
    if (f[i] != 0 && i + 1 < m && f[i + 1] == 2) return false;
  if (f[0] == 2 || f[m - 1] != 0) return false;
  return true;
}
int cal(int b, int cnt) {
  if (cnt < 0) return 0;
  int &ret = dp[b][cnt];
  if (ret != -1) return ret;
  if (b == m) {
    if (!cnt) return ret = 1;
    return ret = 0;
  }
  if (f[b] == 0)
    return ret = cal(b, cnt - 1) + cal(b + 1, cnt) % 1000003;
  else
    return ret = cal(b + 1, cnt + 1);
}
int main() {
  scanf("%s", str);
  n = strlen(str);
  getF();
  if (!ok()) {
    puts("0");
    return 0;
  }
  memset(dp, -1, sizeof(dp));
  printf("%d\n", cal(0, 0));
  return 0;
}
