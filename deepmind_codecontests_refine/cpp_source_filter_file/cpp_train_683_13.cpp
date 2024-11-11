#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5 + 10;
const int LOG = 20;
int rnk[LOG][Max];
pair<pair<int, int>, int> sorter[Max];
int pos[Max];
int lcp[Max];
string s;
int n;
void build() {
  for (int i = 0; i < n; i++) rnk[0][i] = s[i] - 'a';
  for (int lg = 1, sz = 1; lg < LOG; lg++, sz <<= 1) {
    for (int i = 0; i < n; i++)
      sorter[i] = make_pair(
          make_pair(rnk[lg - 1][i], i + sz < n ? rnk[lg - 1][i + sz] : -1), i);
    sort(sorter, sorter + n);
    for (int i = 0, j = 0; i < n; i++)
      rnk[lg][sorter[i].second] = j =
          j + (i > 0 && sorter[i].first != sorter[i - 1].first);
  }
  for (int i = 0; i < n; i++) pos[rnk[LOG - 1][i]] = i;
  for (int lg = LOG; lg--;)
    for (int i = 0; i < n - 1; i++)
      if (lcp[i] + max(pos[i], pos[i + 1]) < n &&
          rnk[lg][pos[i] + lcp[i]] == rnk[lg][pos[i + 1] + lcp[i]])
        lcp[i] += (1 << lg);
}
int L[Max];
int R[Max];
void solve() {
  cin >> s;
  n = s.size();
  for (int i = 0; i < n - 1; i++) lcp[i] = 0;
  build();
  vector<pair<int, int> > vec;
  for (int i = 0; i < n - 1; i++) {
    while (vec.size() && vec.back().first > lcp[i]) vec.pop_back();
    if (vec.size())
      L[i] = vec.back().second + 1;
    else
      L[i] = 0;
    vec.push_back(make_pair(lcp[i], i));
  }
  vec.clear();
  for (int i = n - 1; i--;) {
    while (vec.size() && vec.back().first >= lcp[i]) vec.pop_back();
    if (vec.size())
      R[i] = vec.back().second - 1;
    else
      R[i] = n - 1;
    vec.push_back(make_pair(lcp[i], i));
  }
  long long ans = 1ll * n * (n + 1) / 2;
  for (int i = 0; i < n - 1; i++)
    ans += 2ll * lcp[i] * (i - L[i] + 1) * (R[i] - i);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
