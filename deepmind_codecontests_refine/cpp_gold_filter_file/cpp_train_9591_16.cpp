#include <bits/stdc++.h>
using namespace std;
long long ab(long long x) { return x > 0LL ? x : -x; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k, sum = 0, x;
  cin >> n >> k;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    sum += x;
    v.push_back(x);
  }
  long long ans = -1;
  for (long long i = 0; i < k; i++) {
    long long sum2 = 0;
    for (long long j = i; j < n; j += k) sum2 += v[j];
    ans = max(ans, ab(sum - sum2));
  }
  cout << ans;
  return 0;
}
