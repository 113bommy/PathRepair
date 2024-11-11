#include <bits/stdc++.h>
const int l2 = 3, l5 = 20;
long long x, max = 1, ans = -1, p[14], s[64], w[63][2][2], f[2][100000];
long long gcd(long long a, long long b) {
  if (b == 0) return (a);
  return (gcd(b, a % b));
}
long long lcm(long long a, long long b) { return (a * b / gcd(a, b)); }
long long times(long long a, long long b) {
  long long temp[15], ans = 0;
  memset(temp, 0, sizeof(temp));
  while (b != 0) {
    temp[0]++;
    temp[temp[0]] = b % 10;
    b /= 10;
  }
  for (int i = 1; i <= temp[0]; i++) temp[i] *= a;
  for (int i = 1; i <= 13; i++) {
    temp[i + 1] += temp[i] / 10;
    temp[i] %= 10;
    ans += temp[i] * p[i - 1];
  }
  return (ans);
}
void prework() {
  int i, j, k, l;
  memset(w, 0, sizeof(w));
  w[0][0][0] = 1;
  w[0][1][0] = 1;
  w[0][0][1] = 1;
  s[0] = 1;
  for (i = 1; i <= 62; i++) {
    s[i] = s[i - 1] * 2;
    max += s[i];
    for (j = 0; j <= 1; j++)
      for (k = 0; k <= 1; k++)
        for (l = 0; l <= 1; l++) {
          w[i][j][k] += times(w[i - 1][j][l], w[i - 1][l][k]);
          w[i][j][k] %= p[13];
        }
  }
}
bool check(long long ss, int t) {
  int i, j, k, l;
  long long sum, last[2][2], temp[2][2];
  for (i = 0; i <= 1; i++)
    for (j = 0; j <= 1; j++) last[i][j] = w[0][i][j];
  sum = ss - 1;
  while (sum) {
    i = 0;
    while (s[i + 1] <= sum) i++;
    sum -= s[i];
    for (j = 0; j <= 1; j++)
      for (k = 0; k <= 1; k++) {
        temp[j][k] = last[j][k];
        last[j][k] = 0;
      }
    for (j = 0; j <= 1; j++)
      for (k = 0; k <= 1; k++)
        for (l = 0; l <= 1; l++) {
          last[j][k] += times(temp[j][l], w[i][l][k]);
          last[j][k] %= p[13];
        }
  }
  sum = last[0][0];
  if (sum % p[t] == x % p[t]) {
    if (sum == x)
      if (ans == -1 || ans > ss + 1) ans = ss + 1;
    return (true);
  } else
    return (false);
}
int main() {
  int i, j, k;
  long long temp, l[14], s2[14], s5[14];
  l[0] = p[0] = s2[0] = s5[0] = 1;
  for (i = 1; i <= 13; i++) {
    l[i] = lcm(l2 * s2[i - 1], l5 * s5[i - 1]);
    s2[i] = s2[i - 1] * 2;
    s5[i] = s5[i - 1] * 5;
    p[i] = p[i - 1] * 10;
  }
  f[0][0] = 0;
  f[0][1] = 1;
  prework();
  scanf("%I64d", &x);
  if (x == 0) {
    printf("0");
    return (0);
  } else if (x == 1) {
    printf("1");
    return (0);
  }
  f[0][0] = 1;
  f[0][1] = 0;
  for (i = 1; i <= 13; i++) {
    f[i % 2][0] = 0;
    for (j = 1; j <= f[(i - 1) % 2][0]; j++) {
      temp = f[(i - 1) % 2][j];
      k = l[i] / l[i - 1];
      for (;;) {
        if (temp > 1)
          if (check(temp - 1, i)) {
            f[i % 2][0]++;
            f[i % 2][f[i % 2][0]] = temp;
          }
        k--;
        if (!k || temp > max - l[i - 1]) break;
        temp += l[i - 1];
      }
    }
  }
  printf("%I64d", ans);
  return (0);
}
