#include <bits/stdc++.h>
using namespace std;
int new_pow(int a, int b, int c) {
  int tmp = a;
  while (b > 0) {
    if (b % 2) c = (c * tmp) % 1000000007;
    b >>= 1;
    tmp = (tmp * tmp) % 1000000007;
  }
  return c;
}
int main() {
  int n, k;
  cin >> n >> k;
  int ans;
  ans = new_pow(n - k, n - k, 1);
  ans = new_pow(k, k - 1, ans);
  cout << ans << endl;
  ;
}
