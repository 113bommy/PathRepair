#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
const int mod = 998244353;
int n, k, choose[N];
int mult(int x, int y) { return (long long)x * y % mod; }
int add(int x, int y) {
  if (x + y >= mod) {
    return x + y - mod;
  }
  return x + y;
}
int exp(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) {
      ans = mult(ans, x);
    }
    x = mult(x, x);
    y >>= 1;
  }
  return ans;
}
int inv(int x) { return exp(x, mod - 2); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  choose[k - 1] = 1;
  for (int i = k; i < N; i++) {
    choose[i] = mult(mult(choose[i - 1], i), inv(i - k + 1));
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 2 * i; j <= n; j += i) {
      cnt++;
    }
    ans = add(ans, choose[cnt]);
  }
  cout << ans << '\n';
  return 0;
}
