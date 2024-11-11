#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD1 = 1781601607;
const int MOD2 = 1138640077;
int n;
char str[N];
long long has1[N], has2[N];
long long pw1[N], pw2[N];
long long hash1(int p, int q) {
  long long ans = has1[q];
  long long cnt = has1[p - 1] * pw1[q - p + 1];
  cnt %= MOD1;
  ans -= cnt;
  if (ans < 0) ans += MOD1;
  return ans;
}
long long hash2(int p, int q) {
  long long ans = has2[q];
  long long cnt = has2[p - 1] * pw2[q - p + 1];
  cnt %= MOD2;
  ans -= cnt;
  if (ans < 0) ans += MOD2;
  return ans;
}
void try_this(int i, int j, int k) {
  bool ok = (j >= 1) && (k >= 1);
  ok = ok && (i == 1 || str[1] != 0);
  ok = ok && (j == 1 || str[i + 1] != 0);
  ok = ok && (k == 1 || str[i + j + 1] != 0);
  if (!ok) return;
  long long a1 = hash1(1, i);
  long long b1 = hash1(i + 1, i + j);
  long long c1 = hash1(i + j + 1, i + j + k);
  long long a2 = hash2(1, i);
  long long b2 = hash2(i + 1, i + j);
  long long c2 = hash2(i + j + 1, i + j + k);
  if ((a1 + b1) % MOD1 != c1 || (a2 + b2) % MOD2 != c2) {
    return;
  }
  for (int pos = 1; pos <= i; pos++) {
    printf("%c", str[pos]);
  }
  printf("+");
  for (int pos = i + 1; pos <= i + j; pos++) {
    printf("%c", str[pos]);
  }
  printf("=");
  for (int pos = i + j + 1; pos <= i + j + k; pos++) {
    printf("%c", str[pos]);
  }
  printf("\n");
  exit(0);
}
int main() {
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i < N; i++) {
    pw1[i] = (pw1[i - 1] * 10) % MOD1;
    pw2[i] = (pw2[i - 1] * 10) % MOD2;
  }
  scanf(" %s", str + 1);
  n = strlen(str + 1);
  for (int i = 1; i <= n; i++) {
    has1[i] = (has1[i - 1] * 10) + str[i] - '0';
    has1[i] %= MOD1;
    has2[i] = (has2[i - 1] * 10) + str[i] - '0';
    has2[i] %= MOD2;
  }
  for (int i = 1; i <= n - 2; i++) {
    int j, k;
    if ((n - i) % 2 == 0) {
      j = (n - i) / 2;
      k = n - i - j;
      if (i <= j) try_this(i, j, k);
    }
    if ((n - i - 1) % 2 == 0) {
      j = (n - i - 1) / 2;
      k = n - i - j;
      if (i <= j) try_this(i, j, k);
    }
    j = n - 2 * i;
    k = n - i - j;
    if (i >= j) try_this(i, j, k);
    j = n - 2 * i - 1;
    k = n - i - j;
    if (i >= j) try_this(i, j, k);
  }
  return 0;
}
