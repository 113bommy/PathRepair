#include <bits/stdc++.h>
char A[200050];
int n, f;
int num10[9];
int log10(int n) {
  int k = 0;
  while (n) {
    n /= 10;
    k++;
  }
  return k;
}
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
int pr(int n) {
  int ans = 0;
  for (int i = 8; i > 0; i--)
    if ((n / num10[i]))
      printf("%d+", (n / num10[i]) % 10), ans += (n / num10[i]) % 10;
  printf("%d\n", n % 10), ans += n % 10;
  return ans;
}
int main() {
  num10[0] = 1;
  for (int i = 1; i < 9; i++) num10[i] = num10[i - 1] * 10;
  scanf("%d %s", &n, A + 1);
  for (int i = 1; i <= n; i++) {
    A[i] -= '0';
    f += A[i];
  }
  if (f <= 288) {
    for (int i = 1; i < n; i++) printf("%d+", A[i]);
    printf("%d\n", A[n]);
    if (f == 199) {
      puts("1+99");
      puts("1+0+0");
    } else
      pr(pr(f));
  } else {
    int X = 0, Y = 0, Z = 0, k = log10(f) + 1;
    for (int i = 1; i <= n; i += 3) {
      if (i + 2 <= n) {
        X += A[i] * 100 + A[i + 1] * 10 + A[i + 2];
      } else {
        for (int t = n; t >= i; --t) X += A[t];
        i = n;
      }
    }
    for (int i = 2; i <= n; i += 3)
      if (i + 2 <= n)
        Y += A[i] * 100 + A[i + 1] * 10 + A[i + 2];
      else {
        for (int t = n; t >= i; --t) Y += A[t];
        i = n;
      }
    for (int i = 3; i <= n; i += 3)
      if (i + 2 <= n)
        Z += A[i] * 100 + A[i + 1] * 10 + A[i + 2];
      else {
        for (int t = n; t >= i; --t) Z += A[t];
        i = n;
      }
    int mx = max(X, max(Y, Z));
    if (mx == X) {
      int tmp = f, i;
      for (i = 1; i <= n; i += 3) {
        if ((tmp + A[i] * 99 + A[i + 1] * 9) / num10[k])
          break;
        else {
          printf("%d%d%d+", A[i], A[i + 1], A[i + 2]);
          tmp += A[i] * 99 + A[i + 1] * 9;
        }
      }
      for (; i <= n; i += 3) {
        if ((tmp + A[i] * 9) / num10[k])
          break;
        else {
          printf("%d%d+%d+", A[i], A[i + 1], A[i + 2]);
          tmp += A[i] * 9;
        }
      }
      tmp += A[i] * 9;
      printf("%d%d+", A[i], A[i + 1]);
      for (int j = i + 2; j < n; j++) {
        printf("%d+", A[j]);
      }
      printf("%d\n", A[n]);
      pr(pr(tmp));
    } else if (Y == mx) {
      int tmp = f, i;
      printf("%d+", A[1]);
      for (i = 2; i <= n; i += 3) {
        if ((tmp + A[i] * 99 + A[i + 1] * 9) / num10[k])
          break;
        else {
          printf("%d%d%d+", A[i], A[i + 1], A[i + 2]);
          tmp += A[i] * 99 + A[i + 1] * 9;
        }
      }
      for (; i <= n; i += 3) {
        if ((tmp + A[i] * 9) / num10[k])
          break;
        else {
          printf("%d%d+%d+", A[i], A[i + 1], A[i + 2]);
          tmp += A[i] * 9;
        }
      }
      tmp += A[i] * 9;
      printf("%d%d+", A[i], A[i + 1]);
      for (int j = i + 2; j < n; j++) {
        printf("%d+", A[j]);
      }
      printf("%d\n", A[n]);
      pr(pr(tmp));
    } else if (Z == mx) {
      int tmp = f, i;
      printf("%d+%d+", A[1], A[2]);
      for (i = 3; i <= n; i += 3) {
        if ((tmp + A[i] * 99 + A[i + 1] * 9) / num10[k])
          break;
        else {
          printf("%d%d%d+", A[i], A[i + 1], A[i + 2]);
          tmp += A[i] * 99 + A[i + 1] * 9;
        }
      }
      for (; i <= n; i += 3) {
        if ((tmp + A[i] * 9) / num10[k])
          break;
        else {
          printf("%d%d+%d+", A[i], A[i + 1], A[i + 2]);
          tmp += A[i] * 9;
        }
      }
      tmp += A[i] * 9;
      printf("%d%d+", A[i], A[i + 1]);
      for (int j = i + 2; j < n; j++) {
        printf("%d+", A[j]);
      }
      printf("%d\n", A[n]);
      pr(pr(tmp));
    }
  }
  return 0;
}
