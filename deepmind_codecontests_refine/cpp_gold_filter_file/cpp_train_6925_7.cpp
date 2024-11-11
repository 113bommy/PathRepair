#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200200;
long long d, n, m;
pair<long long, long long> s[maxn];
set<pair<long long, long long> > st;
long long ans;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> d >> n >> m;
  s[0] = {0, 0};
  for (long long i = 1; i <= m; i++) cin >> s[i].first >> s[i].second;
  s[m + 1] = {d, 0};
  sort(s + 1, s + 1 + m);
  long long cur = 0;
  long long pet = n;
  long long nex;
  long long R = 0;
  st.insert({0, 0});
  while (cur != m + 1) {
    st.erase({s[cur].second, cur});
    while (R + 1 <= m + 1 and s[R + 1].first <= s[cur].first + n and
           (!st.size() or st.begin()->first > s[cur].second)) {
      R++;
      st.insert({s[R].second, R});
    }
    if (!st.size()) {
      cout << -1 << endl;
      return 0;
    }
    nex = st.begin()->second;
    if (s[nex].second <= s[cur].second)
      d = max(pet, s[nex].first - s[cur].first) - pet;
    else
      d = n - pet;
    ans += d * s[cur].second;
    pet += d;
    pet -= s[nex].first - s[cur].first;
    while (cur != nex) {
      st.erase({s[cur].second, cur});
      cur++;
    }
  }
  cout << ans << endl;
  return 0;
}
