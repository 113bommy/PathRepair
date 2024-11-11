#include <bits/stdc++.h>
using namespace std;
long long n, k, a, b;
std::vector<long long> pos;
long long cnt(long long i, long long j) {
  auto l = lower_bound(pos.begin(), pos.end(), i) - pos.begin();
  auto h = upper_bound(pos.begin(), pos.end(), j) - pos.begin();
  l--;
  h--;
  return (h - l);
}
long long f(long long i, long long j) {
  long long c = cnt(i, j);
  if (i == j) {
    if (c == 0) {
      return a;
    } else {
      return b * c;
    }
  } else {
    if (c == 0) {
      return a;
    } else {
      return min(f(i, (i + j) / 2) + f((i + j) / 2 + 1, j),
                 b * c * (j - i + 1));
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k >> a >> b;
  for (long long i = 1; i <= k; i++) {
    long long temp;
    cin >> temp;
    pos.push_back(temp);
  }
  sort(pos.begin(), pos.end());
  cout << f(1, (long long)(((long long)1) << n));
  return 0;
}
