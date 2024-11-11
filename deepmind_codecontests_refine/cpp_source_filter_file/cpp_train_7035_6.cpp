#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e5 + 5;
string a, b;
long long asz, bsz;
long long v[N];
bool check(long long k) {
  set<long long> s;
  for (long long i = 0; i < k; i++) {
    s.insert(v[i] - 1);
  }
  long long ind = 0;
  for (long long i = 0; i < asz; i++) {
    if (ind >= bsz) break;
    if (s.find(i) != s.end()) continue;
    if (a[i] == b[ind]) {
      ind++;
    }
  }
  if (ind >= bsz) {
    return true;
  } else {
    return false;
  }
}
long long binsearch(long long lo, long long hi) {
  while (lo < hi) {
    long long mid = (lo + hi + 1) / 2;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b;
  asz = a.size();
  bsz = b.size();
  for (long long i = 0; i < asz; i++) {
    cin >> v[i];
  }
  long long ans = binsearch(0, asz);
  cout << ans;
  return 0;
}
