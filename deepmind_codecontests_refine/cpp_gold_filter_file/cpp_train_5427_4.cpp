#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const long long int int_max = 1e18;
const long long int int_min = -1e18;
using namespace std;
vector<int> v[N];
long long int vis[N] = {0};
long long int sv[N];
int flg = 0;
long long int a[N];
void dfs(long long int k, long long int sum) {
  vis[k] = 1;
  long long int temp = 0, mn = INT_MAX;
  for (long long int i : v[k]) {
    if (!vis[i]) mn = min(mn, sv[i]);
  }
  if (mn == INT_MAX) {
    if (sv[k] == -1) {
      a[k] = 0;
      sv[k] = sum;
    } else
      a[k] = sv[k] - sum;
  } else {
    if (sv[k] == -1) {
      sv[k] = mn;
      a[k] = sv[k] - sum;
    } else
      a[k] = sv[k] - sum;
  }
  for (long long int i : v[k]) {
    if (!vis[i]) {
      dfs(i, sv[k]);
    }
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  long long int n;
  cin >> n;
  for (long long int i = 2; i <= n; i++) {
    long long int p;
    cin >> p;
    v[p].push_back(i);
    v[i].push_back(p);
  }
  for (long long int i = 1; i <= n; i++) cin >> sv[i];
  dfs(1, 0);
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) {
    if (a[i] < 0) flg = 1;
    ans += a[i];
  }
  if (flg)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
}
