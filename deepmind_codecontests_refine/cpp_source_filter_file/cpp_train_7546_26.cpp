#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9;
long long mod = 1e9 + 7;
long long pow(int a, long long b) {
  if (a == 1) return 1;
  if (b == 0) {
    return 1;
  }
  if (b == 1) return a;
  long long ans1 = pow(a, b / 2);
  long long ans = (ans1 % mod) * (ans1 % mod);
  ans = ans % mod;
  if ((b % 2) == 0)
    return ans % mod;
  else
    return ((ans % mod) * (a % mod)) % mod;
}
int main() {
  int n, temp;
  long long ans = 1;
  scanf("%d", &n);
  if (n == 1) {
    cout << 0;
    return 0;
  } else if (n == 2) {
    cout << 4;
    return 0;
  } else {
    for (int i = n + 1; i < 2 * n; i++) {
      ans = ((ans) % mod) * ((i) % mod);
      ans = ans % mod;
    }
    for (int i = 2; i < n; i++) {
      ans = ((ans) % mod) * pow(i, mod - 2);
    }
    ans = (2 * ans) % mod - n;
    ans = ans + mod;
    cout << ans % mod << endl;
  }
  return 0;
}
