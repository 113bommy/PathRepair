#include <bits/stdc++.h>
using namespace std;
long long n, k, v[100000 + 10];
priority_queue<pair<long long, pair<long long, long long> > > pq;
long long calcBuc(int idx, long long nrbuc) {
  if (nrbuc > v[idx]) return 0;
  long long val1 = v[idx] / nrbuc, val2 = val1 + 1;
  long long cnt2 = v[idx] % nrbuc, cnt1 = nrbuc - cnt2;
  return val1 * val1 * cnt1 + val2 * val2 * cnt2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    pq.push({calcBuc(i, 1) - calcBuc(i, 2), {i, 1}});
  }
  k -= n;
  while (k--) {
    pair<long long, pair<long long, long long> > x = pq.top();
    pq.pop();
    pq.push({calcBuc(x.second.first, x.second.second + 1) -
                 calcBuc(x.second.first, x.second.second + 2),
             {x.second.first, x.second.second + 1}});
  }
  long long ans = 0;
  while (!pq.empty()) {
    pair<long long, pair<long long, long long> > x = pq.top();
    pq.pop();
    ans = ans + calcBuc(x.second.first, x.second.second);
  }
  cout << ans << '\n';
  return 0;
}
