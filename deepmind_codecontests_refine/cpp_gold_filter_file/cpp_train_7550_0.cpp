#include <bits/stdc++.h>
void sol() {
  int n;
  std::string s;
  std::cin >> n >> s;
  if (n > 26) {
    std::cout << -1;
  } else {
    int ans = 0;
    std::map<char, bool> a;
    for (int i = 0; i < n; ++i) {
      if (a[s[i]] == 0) {
        a[s[i]] = 1;
      } else {
        ++ans;
      }
    }
    std::cout << ans;
  }
}
int main() {
  int TN = 1;
  for (int i = 0; i < TN; ++i) {
    sol();
  }
  return 0;
}
