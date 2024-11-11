#include <bits/stdc++.h>

void dfs(std::string s,char mx) {
  if (s.size() == n) {
    std::cout << s << std::endl;
    return;
  }
  for (char c = 'a'; c <= mx + 1; ++c) {
    std::string t = s;
    t += c;
    dfs(t, std::max(mx, c));
  }
}

int main() {
  std::cin >> n;
  dfs("", 'a'-1);
  return 0;
}