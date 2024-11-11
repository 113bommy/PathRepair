#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
int32_t main() {
  ios::sync_with_stdio(0);
  int h1, a1, c;
  int h2, a2;
  cin >> h1 >> a1 >> c;
  cin >> h2 >> a2;
  vector<string> ans;
  while (h2 > 0) {
    if (h2 - a2 > 0 and h1 <= a2) {
      ans.push_back("HEAL\n");
      h1 += c;
    } else {
      ans.push_back("STRIKE\n");
      h2 -= a1;
    }
    h1 -= a2;
  }
  cout << (int)(ans.size()) << "\n";
  for (auto s : ans) cout << s;
}
