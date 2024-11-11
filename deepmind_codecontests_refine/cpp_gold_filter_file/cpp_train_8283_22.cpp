#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans;
  ans = ((a ^ b) & (c | d)) ^ ((b & c) | (a ^ d));
  cout << ans;
}
