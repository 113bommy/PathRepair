#include <bits/stdc++.h>
using namespace std;
long long n, p, k;
long long suffix[(long long)1e6];
bool cmp(pair<pair<long long, long long>, long long> x,
         pair<pair<long long, long long>, long long> y) {
  if (x.first.second == y.first.second) {
    return x.first.first > y.first.first;
  } else
    return x.first.second > y.first.second;
}
set<long long> s;
int32_t main() {
  scanf("%lld%lld%lld", &n, &p, &k);
  vector<pair<pair<long long, long long>, long long> > v;
  for (long long i = 0; i < n; i++) {
    long long x, y, z;
    z = i;
    scanf("%lld%lld", &x, &y);
    v.push_back(pair<pair<long long, long long>, long long>(
        pair<long long, long long>(x, y), z));
  }
  sort(v.begin(), v.end(), cmp);
  suffix[n] = 0;
  for (long long i = n - 1; i > 0; i--) {
    suffix[i] = v[i].first.second + suffix[i + 1];
  }
  priority_queue<pair<pair<long long, long long>, long long>,
                 vector<pair<pair<long long, long long>, long long> >,
                 greater<pair<pair<long long, long long>, long long> > >
      pq;
  long long c1 = 0, c2 = 0;
  long long maxvalue = 0, idx = -1;
  for (long long i = 0; (i + p - k) < n; i++) {
    if (pq.size() < k) {
      pq.push(v[i]);
      c1 += v[i].first.first;
    } else {
      if (pq.size() && v[i].first.first > pq.top().first.first) {
        pair<pair<long long, long long>, long long> u = pq.top();
        pq.pop();
        c1 -= u.first.first;
        c1 += v[i].first.first;
        pq.push(v[i]);
      }
    }
    if (pq.size() == k) {
      if ((c1 > maxvalue)) {
        maxvalue = c1;
        idx = i;
      }
    }
  }
  while (pq.size()) pq.pop();
  for (long long i = 0; i <= idx; i++) {
    if (pq.size() < k)
      pq.push(v[i]);
    else {
      if (pq.size() && v[i].first.first > pq.top().first.first) {
        pq.pop();
        pq.push(v[i]);
      }
    }
  }
  long long maxxiidx = -1;
  while (!pq.empty()) {
    printf("%lld ", pq.top().second + 1);
    maxxiidx = max(maxxiidx, pq.top().second);
    s.insert(pq.top().first.second);
    pq.pop();
    p--;
  }
  set<long long> cant;
  for (long long i = idx + 1; i < n; i++) {
    if (p == 0) break;
    if (s.count(v[i].first.second))
      continue;
    else {
      p--;
      cant.insert(i);
      printf("%lld ", v[i].second + 1);
    }
  }
  for (long long i = idx + 1; i < n; i++) {
    if (p == 0) break;
    if (cant.count(i))
      continue;
    else {
      p--;
      printf("%lld\n", v[i].second + 1);
    }
  }
}
