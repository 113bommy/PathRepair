#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int dx[] = {0, 0, 1, -1};
long long int dy[] = {1, -1, 0, 0};
long long int m = 0, n, res, k, ans;
string s2 = "zero", ch = "", s[20], t, s1 = "";
set<long long int> st;
vector<pair<string, long long int> > vm;
vector<pair<long long int, pair<long long int, long long int> > > vvv;
vector<pair<long long int, long long int> > vv, vv1;
vector<long long int> v, v1;
long long int b[300005], dp[1000005], maxIndex[1000005], minIndex[1000005];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int i = 0, x, z, y, j = 0, q, mm = 0, mx = 0, idx = 0, ok = 0,
                l = 0, r = 0, negatif = 0, positif = 0, l1, r1, d;
  set<long long int>::iterator it, it1;
  cin >> q;
  while (q--) {
    cin >> n;
    for (i = 1; i <= n; i++) {
      dp[i] = 1;
      minIndex[i] = 1e9;
      maxIndex[i] = -1;
    }
    st.clear();
    v.clear();
    for (i = 1; i <= n; i++) {
      cin >> b[i];
      minIndex[b[i]] = min(minIndex[b[i]], i);
      maxIndex[b[i]] = max(maxIndex[b[i]], i);
      st.insert(b[i]);
    }
    for (it = st.begin(); it != st.end(); it++) {
      v.push_back((*it));
    }
    res = 0;
    for (i = 1; i < v.size(); i++) {
      long long int prev = v[i - 1];
      if (maxIndex[prev] < minIndex[v[i]]) {
        dp[v[i]] = dp[prev] + 1;
      }
      res = max(res, dp[v[i]]);
    }
    res = (st.size() - res);
    cout << res << '\n';
  }
  return 0;
}
