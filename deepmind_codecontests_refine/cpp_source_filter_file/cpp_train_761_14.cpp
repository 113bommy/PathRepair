#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int mod = 999999937;
const int N = 2 * 1e5 + 10;
set<pair<int, int> > st;
pair<int, int> c[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    a <<= 1, b <<= 1;
    st.insert({a, b});
    c[i].first = a, c[i].second = b;
  }
  int res = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 2; j < n; ++j)
      if (st.count({((c[i].first + c[j].first) >> 1),
                    ((c[i].second + c[j].second) >> 1)}))
        ++res;
  cout << res << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
