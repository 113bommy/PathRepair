#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  string s;
  cin >> s;
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      int l = i;
      while (i + 1 < n && s[i + 1] == '0') i++;
      int r = i;
      p.push_back({l, r});
    }
  }
  vector<int> ans;
  for (int i = 0; i < p.size(); i++) {
    int l = p[i].first;
    while (l + b - 1 <= p[i].second) {
      ans.push_back(l + b - 1);
      l += b;
    }
  }
  cout << ans.size() - (a - 1) << "\n";
  for (int i = 0; i < ans.size() - (a - 1); i++) {
    cout << ans[i] + 1 << " ";
  }
}
