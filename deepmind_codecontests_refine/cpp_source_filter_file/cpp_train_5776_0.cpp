#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 10;
char s[maxn];
int sum[maxn], sum2[maxn];
int isvowel(char c) {
  switch (c) {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'Y':
      return 1;
    default:
      return 0;
  }
}
int main() {
  double ans = 0;
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  for (int i = 1; i <= len; ++i) sum[i] = sum[i - 1] + isvowel(s[i]);
  int maxl = (len + 1) / 2;
  for (int l = 1; l <= maxl; ++l) {
    int L = l, R = len - l + 1;
    sum2[l] = sum2[l - 1] + (sum[R] - sum[L - 1]);
  }
  for (int i = 1; i <= len; ++i) ans += (double)sum2[min(i, len - i + 1)] / i;
  printf("%.6f\n", ans);
  return 0;
}
