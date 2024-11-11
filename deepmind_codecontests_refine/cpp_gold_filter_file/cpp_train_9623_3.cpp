#include <bits/stdc++.h>
using namespace std;
long long arr[1000004];
long long Xor[1000006];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &arr[i]);
    Xor[i] = Xor[i - 1] ^ i;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans ^= arr[i];
    long long z = n / i, y = n % i;
    if (z % 2 == 1) ans ^= Xor[i - 1];
    ans ^= Xor[y];
  }
  cout << ans;
  return 0;
}
