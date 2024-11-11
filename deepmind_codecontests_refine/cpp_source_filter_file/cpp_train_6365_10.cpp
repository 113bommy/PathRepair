#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:667177216")
using namespace std;
const long long MOD = 1000000000 + 7;
const long long MAXN = 3 * 100000 + 100;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  scanf("%I64d%I64d", &n, &k);
  vector<pair<long long, long long>> st(n);
  for (int(i) = 0; (i) < n; (i)++) scanf("%I64d", &st[i].first);
  for (int(i) = 0; (i) < n; (i)++) scanf("%I64d", &st[i].second);
  vector<pair<long long, long long>> cache_st = st;
  long long tl = 0, tr = 1e13;
  while (tl < tr) {
    long long x = (tl + tr) >> 1;
    priority_queue<pair<long long, long long>> s;
    st = cache_st;
    for (int i = 0; i < n; ++i) {
      long long dead = st[i].first / st[i].second;
      s.push(make_pair(-dead, i));
    }
    bool ok = true;
    long long minute = 0;
    while (true) {
      auto cur = s.top();
      s.pop();
      long long idx = cur.second;
      if (minute >= k || -cur.first >= k) {
        break;
      }
      if (st[idx].first - st[idx].second * minute < 0) {
        ok = false;
        break;
      }
      st[idx].first += x;
      s.push(make_pair(-st[idx].first / st[idx].second, idx));
      minute++;
    }
    if (ok) {
      tr = x;
    } else {
      tl = x + 1;
    }
  }
  if (tl > 1e15) {
    cout << -1;
  } else {
    cout << tl;
  }
  return 0;
}
