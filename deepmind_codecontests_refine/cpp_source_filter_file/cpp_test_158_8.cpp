#include <bits/stdc++.h>
using namespace std;
void read(vector<int64_t> &a);
void read(vector<string> &a);
void read(vector<vector<int64_t>> &a);
void read(vector<pair<int64_t, int64_t>> &a);
void solve() {
  int64_t n, m;
  cin >> n >> m;
  vector<int64_t> exp(n);
  read(exp);
  vector<string> mat(n);
  read(mat);
  int64_t best = 0;
  vector<int64_t> ret;
  for (int64_t x = 0; x < (1 << n); x++) {
    string b = std::bitset<32>(x).to_string();
    reverse(b.begin(), b.end());
    vector<pair<int64_t, int64_t>> order(m);
    for (int64_t i = 0; i < m; i++) {
      int64_t temp = 0;
      for (int64_t j = 0; j < n; j++) {
        if (b[j] == '1')
          temp += (mat[j][i] - '0');
        else
          temp -= (mat[j][i] - '0');
      }
      order[i] = {temp, i};
    }
    sort(order.begin(), order.end());
    reverse(order.begin(), order.end());
    int64_t ans = 0;
    for (int64_t i = 0; i < n; i++) {
      if (b[i] == '0')
        ans += exp[i];
      else
        ans -= exp[i];
    }
    int64_t tog = m;
    vector<int64_t> haha(m);
    for (auto x : order) {
      ans += (x.first) * (tog);
      haha[x.second] = tog;
      tog--;
    }
    if (ans > best) {
      best = ans;
      ret = haha;
    }
  }
  for (int64_t i : ret) cout << i << " ";
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t t = 1;
  cin >> t;
  for (int64_t tt = 1; tt <= t; tt++) {
    solve();
  }
  return 0;
}
void read(vector<int64_t> &a) {
  for (int64_t i = 0; i < a.size(); i++) cin >> a[i];
}
void read(vector<string> &a) {
  for (int64_t i = 0; i < a.size(); i++) cin >> a[i];
}
void read(vector<vector<int64_t>> &a) {
  for (int64_t i = 0; i < a.size(); i++)
    for (int64_t j = 0; j < a[i].size(); j++) cin >> a[i][j];
}
void read(vector<pair<int64_t, int64_t>> &a) {
  for (int64_t i = 0; i < a.size(); i++) cin >> a[i].first >> a[i].second;
}
