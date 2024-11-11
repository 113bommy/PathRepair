#include <bits/stdc++.h>
#pragma optimize("O3")
using namespace std;
const int up = 3e5 + 5;
int n;
int b[up], prefbits[up], even[up], odd[up];
long long a;
int bit_count(long long a) {
  int cnt = 0;
  for (int i = 0; i < 61; i++) {
    if ((a & (1ll << i))) {
      cnt++;
    }
  }
  return cnt;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a);
    b[i] = bit_count(a);
  }
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    prefbits[i] = prefbits[i - 1] + b[i];
    even[i] = even[i - 1];
    odd[i] = odd[i - 1];
    if ((prefbits[i] & 1) == 0) {
      even[i]++;
    } else {
      odd[i]++;
    }
  }
  int parity = 0;
  for (int i = 1; i <= n; i++) {
    int maxbit = 0;
    for (int j = i; j <= i + 62 && j <= n; j++) {
      maxbit = max(maxbit, b[j]);
      int sum = prefbits[j] - prefbits[i - 1];
      if ((sum & 1) == 0 && maxbit + maxbit <= sum) {
        res++;
      }
    }
    if (i + 62 >= n) continue;
    parity = prefbits[i - 1] % 2;
    if (!parity) {
      res = res + 1ll * (even[n] - even[i + 62]);
    } else {
      res = res + 1ll * (odd[n] - odd[i + 62]);
    }
  }
  printf("%I64d\n", res);
  return 0;
}
