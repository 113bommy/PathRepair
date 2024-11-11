#include <bits/stdc++.h>
using namespace std;
int cnt[27];
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    return cout << "YES\n", 0;
  }
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    if (cnt[s[i] - 'a'] > 1) {
      return cout << "YES\n", 0;
    }
  }
  cout << "NO\n";
  return 0;
}
