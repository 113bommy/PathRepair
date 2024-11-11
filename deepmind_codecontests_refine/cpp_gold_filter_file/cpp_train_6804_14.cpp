#include <bits/stdc++.h>
using namespace std;
int n, k;
int num[100010];
int main(int argc, char const *argv[]) {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> num[i];
  sort(num + 1, num + 1 + n);
  long long sum = 0;
  long long maxx = -1, ma;
  int i = 1, j = 1;
  for (; i <= n; i++) {
    sum += num[i];
    while ((num[i] * (i - j + 1LL) - sum) > k) {
      sum -= num[j++];
    }
    if (maxx < i - j + 1LL) {
      maxx = i - j + 1;
      ma = num[i];
    }
  }
  printf("%lld %lld\n", maxx, ma);
  return 0;
}
