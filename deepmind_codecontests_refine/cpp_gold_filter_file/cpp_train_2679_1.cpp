#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long int, long long int>>> v(10005);
long long int n, q, dp[10005], res[10005], hell = pow(10, 9) + 7;
void add(long long int x) {
  for (long long int i = n; i >= x; i--) {
    dp[i] += dp[i - x];
    if (dp[i] >= hell) dp[i] -= hell;
  }
}
void del(long long int x) {
  for (long long int i = x; i <= n; i++) {
    dp[i] -= dp[i - x];
    if (dp[i] < 0) dp[i] += hell;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> q;
  for (long long int i = 0; i < q; i++) {
    long long int l, r, x;
    cin >> l >> r >> x;
    v[l].push_back({x, 1});
    v[r + 1].push_back({x, -1});
  }
  dp[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 0; j < v[i].size(); j++)
      if (v[i][j].second == 1)
        add(v[i][j].first);
      else
        del(v[i][j].first);
    for (long long int j = 1; j <= n; j++)
      if (dp[j]) res[j] = 1;
  }
  vector<long long int> jok;
  for (long long int i = 1; i <= n; i++)
    if (res[i]) jok.push_back(i);
  cout << jok.size() << endl;
  for (long long int i = 0; i < jok.size(); i++) cout << jok[i] << " ";
}
