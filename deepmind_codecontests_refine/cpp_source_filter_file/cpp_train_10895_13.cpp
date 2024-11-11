#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20);
const int mod = 1e9 + 7;
int n, q, a[N];
int ans[N];
bool have[N];
vector<int> v;
vector<pair<pair<int, int>, int> > Q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    int l, x;
    cin >> l >> x;
    Q.push_back(pair<pair<int, int>, int>(pair<int, int>(l, x), i));
  }
  sort(Q.begin(), Q.end());
  int j = 1;
  v.push_back(0);
  have[0] = 1;
  int res = 1;
  for (int i = 0; i < q; ++i) {
    for (; j <= Q[i].first.first; ++j) {
      if (!have[a[j]]) {
        int sz = v.size();
        for (int k = 0; k < sz; ++k)
          if (!have[v[k] ^ a[j]])
            have[v[k] ^ a[j]] = 1, v.push_back(v[k] ^ a[j]);
      } else
        res = res * 2 % mod;
    }
    ans[Q[i].second] = res * have[Q[i].first.second];
  }
  for (int i = 1; i <= q; ++i) cout << ans[i] << "\n";
}
