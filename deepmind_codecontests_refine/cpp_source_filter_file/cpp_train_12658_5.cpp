#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
const long long N = 3e5 + 10;
const long long MOD = 1e9 + 7;
bool have[N];
long long n, k, a[N], pos[N], nxt[N];
set<pair<long long, long long>> s;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 0; i < N; i++) pos[i] = n + 1;
  for (long long i = n; i >= 1; i--) {
    nxt[i] = pos[a[i]];
    pos[a[i]] = i;
  }
  long long ans = 0, tot = 0;
  for (long long i = 1; i <= n; i++) {
    if (have[a[i]]) {
      s.erase({pos[a[i]], a[i]});
      pos[a[i]] = nxt[i];
      s.emplace(pos[a[i]], a[i]);
      continue;
    }
    if (tot == k) {
      tot--;
      auto it = prev(s.end());
      have[it->second] = false;
      s.erase(it);
    }
    have[a[i]] = true;
    ans++, tot++;
    pos[a[i]] = nxt[i];
    s.emplace(pos[a[i]], a[i]);
  }
  cout << ans;
  return 0;
}
