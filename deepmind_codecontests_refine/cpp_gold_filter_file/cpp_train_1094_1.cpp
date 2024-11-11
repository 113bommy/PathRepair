#include <bits/stdc++.h>
using namespace std;
int ternary_search(int left, int right, int mindex);
long long calculate(int len, int mindex);
const int SIZE = 2e5 + 5;
long long a[SIZE], asum[SIZE];
int n;
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    if (n == 1 || n == 2) {
      printf("1\n");
      printf("%I64d\n", a[1]);
      continue;
    }
    sort(a + 1, a + 1 + n);
    asum[0] = 0;
    for (int i = 1; i <= n; i++) asum[i] = asum[i - 1] + a[i];
    long long res_cal = 0;
    int res_len = 0;
    int res_mid = 1;
    for (int i = 2; i <= n - 1; i++) {
      int left = 0, right = min(i - 1, n - i);
      int tlen = ternary_search(left, right, i);
      long long tcal = calculate(tlen, i) - (2 * tlen + 1) * a[i];
      if (tcal * (2 * res_len + 1) > res_cal * (2 * tlen + 1)) {
        res_cal = tcal;
        res_len = tlen;
        res_mid = i;
      }
    }
    printf("%d\n", 2 * res_len + 1);
    for (int i = res_mid - res_len; i <= res_mid; i++) {
      printf("%I64d", a[i]);
      printf(" ");
    }
    for (int i = n - res_len + 1; i <= n; i++) {
      printf("%I64d", a[i]);
      printf(i == n ? "\n" : " ");
    }
  }
  return 0;
}
int ternary_search(int left, int right, int mindex) {
  int lmid, rmid;
  while (left < right) {
    lmid = (2 * left + right) / 3;
    rmid = (left + 2 * right + 2) / 3;
    if (calculate(lmid, mindex) * (2 * rmid + 1) <
        calculate(rmid, mindex) * (2 * lmid + 1)) {
      left = lmid + 1;
    } else {
      right = rmid - 1;
    }
  }
  return left;
}
long long calculate(int len, int mindex) {
  long long sum1 = asum[mindex] - asum[mindex - len - 1];
  long long sum2 = asum[n] - asum[n - len];
  return (sum1 + sum2);
}
