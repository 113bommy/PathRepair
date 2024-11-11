#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 100;
priority_queue<long long, vector<long long>, greater<long long> > q;
pair<long long, long long> a[N];
long long n;
signed main() {
  cin >> n;
  cin >> a[1].first >> a[1].second;
  for (long long i = 2; i <= n; i++) {
    long long t, w;
    scanf("%lld%lld", &t, &w);
    a[i] = make_pair(t, w);
  }
  sort(a + 2, a + n + 1);
  long long rank = 1e8 + 100;
  long long cur = a[1].first;
  long long j = n;
  while (1) {
    for (; j >= 2 && a[j].first > cur; j--)
      q.push(a[j].second - a[j].first + 1);
    rank = min(rank, (long long)q.size() + 1);
    if (q.size() && cur >= q.top()) {
      cur -= q.top();
      q.pop();
    } else {
      printf("%lld", rank);
      return 0;
    }
  }
}
