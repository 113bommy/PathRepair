#include <bits/stdc++.h>
using namespace std;
long long n, s;
long long F(long long x) {
  long long cnt = 0;
  long long t = x;
  while (x) {
    cnt += x % 10ll;
    x /= 10ll;
  }
  return t - cnt;
}
int main() {
  cin >> n >> s;
  long long low = 0, high = n + 10;
  while (low < high) {
    long long mid = low + (high - low) / 2ll;
    if (F(mid) >= s)
      high = mid;
    else
      low = mid + 1;
  }
  long long ans = max(0ll, n - high + 1);
  cout << ans << endl;
  return 0;
}
