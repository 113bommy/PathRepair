#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)2e9;
const long long md = 1000000007;
long long dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
long long power(long long a, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans *= a;
    p /= 2;
    a *= a;
    ans %= md;
    a %= md;
  }
  return ans;
}
long long mdinv(long long a) { return power(a, md - 2); }
const long long N = 2e5 + 10;
long long cnt[N];
long long lst[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, q;
  cin >> n >> q;
  vector<long long> v(n);
  for (long long i = 0; i < (long long)n; i++) {
    cin >> v[i];
    cnt[v[i]]++;
    lst[v[i]] = i;
  }
  vector<set<long long>> vh;
  for (long long i = 0; i < n;) {
    set<long long> st;
    long long j = i;
    long long f = lst[v[i]];
    while (j <= f) {
      st.insert(v[j]);
      f = max(f, lst[v[j]]);
      j++;
    }
    i = j;
    vh.push_back(st);
  }
  long long ans = 0;
  for (auto& st : vh) {
    long long mn = INT_MIN;
    long long sum = 0;
    for (long long e : st) {
      mn = max(mn, cnt[e]);
      sum += cnt[e];
    }
    ans += sum - mn;
  }
  cout << ans;
}
