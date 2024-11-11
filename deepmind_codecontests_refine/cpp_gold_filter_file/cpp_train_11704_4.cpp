#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 100;
bool mark[N];
long long a[N], p[N];
set<long long> s;
long long fen[N];
void add(long long x, long long val) {
  for (x++; x < N; x += x & -x) {
    fen[x] += val;
  }
  return;
}
long long get(long long x) {
  long long ans = 0;
  for (; x > 0; x -= x & -x) {
    ans += fen[x];
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    add(i, 1);
    cin >> a[i];
    a[i]--;
    p[a[i]] = i;
  }
  for (long long i = 0, x; i < k; i++) {
    cin >> x;
    x--;
    mark[x] = true;
  }
  s.insert(n);
  s.insert(-1);
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    auto it = s.lower_bound(p[i]);
    long long r = *it;
    it--;
    long long l = *it;
    l++;
    if (!mark[i]) {
      ans += get(r) - get(l);
      add(p[i], -1);
    } else {
      s.insert(p[i]);
    }
  }
  cout << ans << "\n";
  return 0;
}
