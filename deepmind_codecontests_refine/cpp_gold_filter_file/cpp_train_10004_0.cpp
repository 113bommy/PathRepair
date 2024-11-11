#include <bits/stdc++.h>
using namespace std;
int n, k;
string s, ans;
set<pair<int, char>> st;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  cin >> s;
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (cnt1 >= k / 2) break;
    if (s[i] == '(') {
      st.insert(make_pair(i, '('));
      cnt1++;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (cnt2 >= k / 2) break;
    if (s[i] == ')') {
      st.insert(make_pair(i, ')'));
      cnt2++;
    }
  }
  for (auto u : st) ans.push_back(u.second);
  cout << ans;
}
