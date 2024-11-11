#include <bits/stdc++.h>
using namespace std;
bool good(string s, int k) {
  vector<int> c(10, 0);
  for (int i = 0; i < (int)s.size(); i++) {
    c[s[i] - '0']++;
  }
  for (int i = 0; i < k; i++) {
    if (c[i] == 0) return 0;
  }
  return 1;
}
int main() {
  int n, k, ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (good(s, k)) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
