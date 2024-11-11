#include <bits/stdc++.h>
using namespace std;
long long ask(long long x) {
  long long y = 1000000007 - 2, now = 1;
  while (y) {
    if (y % 2) now = (now * x) % 1000000007;
    x = (x * x) % 1000000007;
    y >>= 1;
  }
  return now;
}
long long num[200005], nums[200005];
long long ni[200005];
int main() {
  int n;
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &num[i]);
    ni[i] = ask(i);
  }
  if (n > 2) {
    if (n % 2) {
      for (int i = 1; i < n; i++) {
        if (i % 2)
          nums[i] = (num[i] + num[i + 1]) % 1000000007;
        else
          nums[i] = (num[i] - num[i + 1]) % 1000000007;
      }
      n--;
    } else {
      for (int i = 1; i <= n; i++) nums[i] = num[i];
    }
    long long temp = 1, temp2 = n / 2;
    if ((n / 2) % 2) {
      ans = (nums[1] + nums[2]) % 1000000007;
      for (int i = 3; i < n; i += 2) {
        temp2--;
        temp = (((temp * temp2) % 1000000007) * ni[i / 2]) % 1000000007;
        ans = ((ans + temp * nums[i]) % 1000000007 + temp * nums[i + 1]) %
              1000000007;
      }
    } else {
      ans = (nums[1] - nums[2]) % 1000000007;
      for (int i = 3; i < n; i += 2) {
        temp2--;
        temp = (((temp * temp2) % 1000000007) * ni[i / 2]) % 1000000007;
        ans = ((ans + temp * nums[i]) % 1000000007 - temp * nums[i + 1]) %
              1000000007;
      }
    }
  } else
    ans = num[1];
  printf("%lld\n", (ans + 1000000007) % 1000000007);
  return 0;
}
