#include <bits/stdc++.h>
using namespace std;
long long f[25][3][3];
int b[25], Q;
long long getH() {
  char s[20];
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  long long re = 0ll;
  for (int i = 1; i <= len; i++) {
    int tmp;
    if ('0' <= s[i] && s[i] <= '9')
      tmp = s[i] - '0';
    else
      tmp = s[i] - 'a' + 10;
    re = re * 16ll + tmp;
  }
  return re;
}
long long calc_maxn(int maxn) {
  memset(f, 0, sizeof(f));
  f[16][1][0] = 1;
  for (int i = 16; i > 0; i--) {
    if (i * 4 - 1 >= maxn && maxn >= i * 4 - 4) {
      int tmp = maxn % 4;
      for (int j = 0; j < b[i - 1] && j <= maxn; j++) {
        if (j & (1 << tmp)) f[i - 1][0][1] += f[i][1][1];
      }
      if (b[i - 1] <= maxn && (b[i - 1] & (1 << tmp)))
        f[i - 1][1][1] += f[i][1][1];
      for (int j = 0; j < b[i - 1] && j <= maxn; j++) {
        if (j & (1 << tmp)) f[i - 1][0][(j == maxn)] += f[i][1][0];
      }
      if (b[i - 1] <= maxn && (b[i - 1] & (1 << tmp))) {
        f[i - 1][1][(b[i - 1] == maxn)] += f[i][1][0];
      }
      for (int j = 0; j <= maxn; j++) {
        if (j & (1 << tmp)) f[i - 1][0][1] += f[i][0][1];
      }
      for (int j = 0; j <= maxn; j++) {
        if (j & (1 << tmp)) f[i - 1][0][(j == maxn)] += f[i][0][0];
      }
      continue;
    }
    for (int j = 0; j < b[i - 1] && j <= maxn; j++) {
      f[i - 1][0][1] += f[i][1][1];
    }
    if (b[i - 1] <= maxn) f[i - 1][1][1] += f[i][1][1];
    for (int j = 0; j < b[i - 1] && j <= maxn; j++) {
      f[i - 1][0][(j == maxn)] += f[i][1][0];
    }
    if (b[i - 1] <= maxn) {
      f[i - 1][1][(b[i - 1] == maxn)] += f[i][1][0];
    }
    for (int j = 0; j <= maxn; j++) {
      f[i - 1][0][1] += f[i][0][1];
    }
    for (int j = 0; j <= maxn; j++) {
      f[i - 1][0][(j == maxn)] += f[i][0][0];
    }
  }
  return f[0][0][1] + f[0][1][1];
}
long long calc(long long m) {
  if (m < 0) return 0ll;
  int tmp = 0;
  memset(b, 0, sizeof(b));
  while (m) {
    b[tmp] = m % 16;
    m /= 16;
    tmp++;
  }
  long long re = 0ll;
  for (int i = 1; i <= 15; i++) {
    re += calc_maxn(i);
  }
  return re;
}
int main() {
  scanf("%d", &Q);
  for (int cas = 1; cas <= Q; cas++) {
    long long L = 0ll, R = 0ll;
    L = getH() - 1ll;
    R = getH();
    printf("%lld\n", calc(R) - calc(L - 1));
  }
  return 0;
}
