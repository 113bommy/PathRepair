#include <bits/stdc++.h>
using namespace std;
int Diversity(string s, int n) {
  if (n > s.length()) return -1;
  set<char> distinct;
  for (int i = 0; i < s.length(); i++) {
    distinct.insert(s[i]);
  }
  int ans = n - distinct.size();
  if (ans < 0) return -1;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s;
  cin >> s >> n;
  int ans = Diversity(s, n);
  (ans == -1) ? cout << "impossible" << '\n' : cout << ans << '\n';
  return 0;
}
