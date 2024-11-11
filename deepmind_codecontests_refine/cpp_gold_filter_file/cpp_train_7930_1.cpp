#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1, maxm = 1e6 + 1, MOD = 1e9 + 7;
const long long oo = 1e18;
void input() {
  if (fopen("kkk"
            ".inp",
            "r")) {
    freopen(
        "kkk"
        ".inp",
        "r", stdin);
    freopen(
        "kkk"
        ".out",
        "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  ios_base::sync_with_stdio(NULL);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
double pi = acos(-1);
int n;
int dp[maxm], l[maxm], r[maxm], a[maxm];
int main() {
  input();
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v;
    v.clear();
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i]--;
      l[i] = INT_MAX;
      r[i] = -INT_MAX;
      dp[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      v.push_back(a[i]);
      l[a[i]] = min(l[a[i]], i);
      r[a[i]] = max(r[a[i]], i);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int res = n;
    for (int i = v.size() - 1; i >= 0; --i) {
      if (i + 1 == v.size() || r[v[i]] >= l[v[i + 1]])
        dp[i] = 1;
      else
        dp[i] = 1 + dp[i + 1];
      res = min(res, int(v.size()) - dp[i]);
    }
    cout << res << '\n';
  }
  return 0;
}
