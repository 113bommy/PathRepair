#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)2 * 1e9;
const long long MOD = (long long)1e9 + 7;
const long long p = 239;
const long long MAX_N = 1000;
const long double pi = 3.1415926;
const long double eps = 1e-6;
bool comp(pair<pair<long long, long long>, long long> a,
          pair<pair<long long, long long>, long long> b) {
  if (a.first.first < b.first.first)
    return true;
  else if (a.first.first > b.first.first)
    return false;
  else
    return a.second < b.second;
}
int main() {
  long long d, n, q;
  scanf("%I64d %I64d %I64d", &d, &n, &q);
  vector<pair<pair<long long, long long>, long long> > v;
  v.push_back(make_pair(make_pair(n, 0), 1));
  v.push_back(make_pair(make_pair(d, 0), 0));
  for (long long i = 0; i < q; i++) {
    long long x, p;
    scanf("%I64d %I64d", &x, &p);
    v.push_back(make_pair(make_pair(x, p), 0));
    v.push_back(make_pair(make_pair(min(x + n, d), p), 1));
  }
  sort(v.begin(), v.end(), comp);
  long long curr = 0, cnt = 0;
  map<long long, long long> m;
  m[0] = 1;
  for (long long i = 0; i < v.size() && v[i].first.first <= d;) {
    long long pos = v[i].first.first;
    if (m.size() == 0) {
      printf("%d", -1);
      return 0;
    }
    cnt += (pos - curr) * (m.begin()->first);
    while (i < v.size() && v[i].first.first == pos && v[i].second == 0) {
      if (m.find(v[i].first.second) == m.end()) m[v[i].first.second] = 0;
      m[v[i].first.second]++;
      i++;
    }
    while (i < v.size() && v[i].first.first == pos && v[i].second == 1) {
      m[v[i].first.second]--;
      if (m[v[i].first.second] == 0) m.erase(v[i].first.second);
      i++;
    }
    curr = pos;
  }
  printf("%I64d", cnt);
  return 0;
}
