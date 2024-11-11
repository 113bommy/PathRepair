#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
using ull = unsigned long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  set<char> vowles = {'a', 'e', 'o', 'u', 'i', 'Y'};
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans = "";
  for (int i = 0; i < n; ++i) {
    if (vowles.count(ans[ans.length() - 1]) && vowles.count(s[i])) continue;
    ans += s[i];
  }
  cout << ans;
}
