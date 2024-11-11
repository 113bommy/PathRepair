#include <bits/stdc++.h>
const int INF = 1 << 29;
int count(std::string s) {
  int res = 0;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'V' && s[i + 1] == 'K') res++;
  }
  return res;
}
int solve(std::string &s) {
  int cnt = 0;
  int n = (int)s.size();
  int ans = count(s);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'V') {
      s[i] = 'K';
      ans = std::max(ans, count(s));
      s[i] = 'V';
    }
    if (s[i] == 'K') {
      s[i] = 'V';
      ans = std::max(ans, count(s));
      s[i] = 'K';
    }
  }
  return ans;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  ;
  std::string s;
  std::cin >> s;
  std::cout << solve(s);
  return 0;
}
