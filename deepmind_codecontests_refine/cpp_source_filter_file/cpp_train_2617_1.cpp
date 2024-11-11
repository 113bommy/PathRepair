#include <bits/stdc++.h>
using namespace std;
long long n, k, A, B, x;
vector<long long> idx;
long long Cost(long long beg, long long end) {
  auto r = upper_bound(idx.begin(), idx.end(), end),
       l = upper_bound(idx.begin(), idx.end(), beg - 1);
  if (r - l == 0) return A;
  if (beg == end) return (r - l) * B;
  long long mid = (beg + end) >> 1;
  return min((r - l) * B * (end - beg + 1),
             Cost(beg, mid) + Cost(mid + 1, end));
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> A >> B;
  for (long long i = 1; i <= k; ++i) cin >> x, idx.push_back(x);
  sort(idx.begin(), idx.end());
  idx.push_back(1 << (n + 1));
  cout << Cost(1, 1 << n) << endl;
  return 0;
}
