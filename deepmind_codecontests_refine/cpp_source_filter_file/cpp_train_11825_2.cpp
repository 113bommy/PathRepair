#include <bits/stdc++.h>
using namespace std;
long long n, b[66], l, r;
long long cnt(long long k) {
  long long ans = 0;
  while (k % 2) k /= 2, ans++;
  return ans;
}
int main() {
  cin >> n >> l >> r;
  long long nn = n;
  long long i;
  for (i = 0; nn; i++, nn /= 2) b[i] = nn % 2;
  reverse(b, b + i);
  long long ans = 0;
  for (long long i = l; i <= r; i++) {
    long long x = cnt(i);
    ans += b[x];
  }
  cout << ans;
}
