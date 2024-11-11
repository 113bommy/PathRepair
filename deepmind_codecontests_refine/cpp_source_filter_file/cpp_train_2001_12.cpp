#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int n;
string s;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> n >> s;
  vector<int> ans(n);
  vector<int> max_inc(26);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = s[i] - 'a' + 1; j < 26; j++) {
      ans[i] = max(ans[i], max_inc[j] + 1);
    }
    max_inc[s[i] - 'a'] = max(max_inc[s[i] - 'a'], ans[i]);
    mx = max(mx, ans[i]);
  }
  cout << mx << "\n";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
