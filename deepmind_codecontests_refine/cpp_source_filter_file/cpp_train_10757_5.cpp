#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
char str1[1010], str2[1010];
long long dpA[100010], dpB[100010];
int main() {
  scanf("%s", str1);
  scanf("%s", str2);
  int A = 0, B, N, len = strlen(str1);
  scanf("%d", &N);
  for (int i = 1; i < len; i++) {
    bool flag = true;
    for (int j = 0; j < len; j++) {
      if (str1[(i + j) % len] != str2[j]) {
        flag = false;
        break;
      }
    }
    if (flag) A++;
  }
  B = len - A;
  if (!strcmp(str1, str2))
    dpA[0] = 1, dpB[0] = 0;
  else
    dpA[0] = 0, dpB[0] = 1;
  for (int i = 1; i <= N; i++) {
    dpA[i] = (dpA[i - 1] * (A - 1) % mod + dpB[i - 1] * A % mod) % mod;
    dpB[i] = (dpB[i - 1] * (B - 1) % mod + dpA[i - 1] * B % mod) % mod;
  }
  printf("%I64d\n", dpA[N]);
  return 0;
}
