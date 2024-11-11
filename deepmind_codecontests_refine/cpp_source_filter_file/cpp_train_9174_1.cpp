#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long bp[65536 * 2];
long long check(long long len) {
  long long i = 0;
  long long cnt = 0;
  while (i < n) {
    long long j = i;
    while (j < n and bp[j + 1] - bp[i] + 1 <= len) j++;
    i = j + 1, cnt++;
  }
  return cnt <= k;
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  long long ans = n;
  set<long long> s;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &bp[i]);
    if (i) s.insert(bp[i] - bp[i - 1] - 1);
  }
  while (s.size() >= k) {
    ans += *s.begin();
    s.erase(s.begin());
  }
  cout << ans;
}
