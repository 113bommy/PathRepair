#include <bits/stdc++.h>
using namespace std;
long long sum[5000005];
void markMultiples(bool arr[], int a, int n) {
  int i = 2, num, z;
  sum[a] = 1;
  while ((num = i * a) <= n) {
    arr[num - 1] = 1;
    z = num;
    while ((num % a) == 0) {
      sum[z]++;
      num /= a;
    }
    ++i;
  }
}
void sieve() {
  bool arr[5000005];
  memset(arr, 0, sizeof(arr));
  for (int i = 1; i < 5000005; ++i) {
    if (arr[i] == 0) {
      markMultiples(arr, i + 1, 5000005);
    }
  }
}
int main() {
  int t, a, b, i;
  cin >> t;
  sieve();
  for (i = 1; i < 5000005; i++) {
    sum[i] += sum[i - 1];
  }
  while (t--) {
    scanf("%d%d", &a, &b);
    printf("%I64d\n", (sum[a] - sum[b]));
  }
  return 0;
}
