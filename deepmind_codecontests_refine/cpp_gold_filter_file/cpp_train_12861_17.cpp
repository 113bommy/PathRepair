#include <bits/stdc++.h>
using namespace std;
long long N;
long long get(long long x) {
  long long res = 0ll;
  for (long long n = 2; n <= 200000ll; ++n) {
    long long sum = (n * 1ll * n * 1ll * n);
    res += (x / sum);
    if (res > N) return N + 1;
  }
  return res;
}
int main() {
  cin >> N;
  long long start = 1ll;
  long long end = (long long)1e16;
  long long mid;
  int iter = 100;
  while (iter--) {
    mid = (start + end) / 2ll;
    long long ways = get(mid);
    if (ways >= N)
      end = mid;
    else
      start = mid;
  }
  for (long long n = max((long long)1, mid - 5ll); n <= (mid + 5ll); ++n) {
    if (get(n) == N) {
      cout << n << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
