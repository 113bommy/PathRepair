#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 5, inf = 1e9 + 7;
long long n, k;
set<pair<long long, long long> > st;
long long cumm[N], m[26];
string s;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long i, j, a, b, ans = 1;
  cin >> n >> k;
  cin >> s;
  s = '#' + s;
  for (i = 0; i < k; i++) st.insert(pair<long long, long long>(m[i], i));
  for (i = 1; i < s.size(); i++) {
    a = s[i] - 'a';
    st.erase(st.find(pair<long long, long long>(m[a], a)));
    if (m[a])
      cumm[i] = cumm[i - 1] - cumm[m[a] - 1];
    else
      cumm[i] = cumm[i - 1] + 1;
    m[a] = i;
    st.insert(pair<long long, long long>(m[a], a));
    cumm[i] = (cumm[i] % inf + cumm[i - 1] + inf) % inf;
  }
  for (i = s.size(); i < s.size() + n; i++) {
    a = st.begin()->second;
    st.erase(st.find(pair<long long, long long>(m[a], a)));
    if (m[a])
      cumm[i] = cumm[i] - cumm[m[a] - 1];
    else
      cumm[i] = cumm[i - 1] + 1;
    m[a] = i;
    st.insert(pair<long long, long long>(m[a], a));
    cumm[i] = (cumm[i] % inf + cumm[i - 1] + inf) % inf;
  }
  cout << (cumm[i - 1] + 1) % inf;
}
