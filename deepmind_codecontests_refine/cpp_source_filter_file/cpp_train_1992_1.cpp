#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 4, inf = 1e9;
long long const md = 998244353;
long long dp[N], a[N], pref[N][5], n, k, m, x1, y, x, bbp, kk, sz, ans;
long long q, qq;
char ch;
vector<long long> v[N];
bool us[N];
pair<long long, long long> p[N];
string second, t;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  set<long long> st;
  st.insert(1);
  us[1] = 1;
  while (!st.empty()) {
    int g = *st.begin();
    st.erase(st.begin());
    cout << g << " ";
    for (int i = 0; i < v[g].size(); i++) {
      int to = v[g][i];
      if (us[to]) continue;
      st.insert(to);
      us[to] = 1;
    }
  }
  return 0;
}
