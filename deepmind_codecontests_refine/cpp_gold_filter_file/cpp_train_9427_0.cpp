#include <bits/stdc++.h>
const int MAXN = 10001;
int n, k;
std::string s[MAXN], last;
bool cmp(const std::string &a, const std::string &b) {
  return (a.size() < b.size());
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
  }
  std::cin >> last;
  std::sort(s + 1, s + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    int j = i;
    while (i + 1 <= n && s[i + 1].size() == s[i].size()) {
      i++;
    }
    for (int p = j; p <= i; p++) {
      if (s[p] == last) {
        std::cout << (j - 1) / k * 5 + j << " " << (i - 1) / k * 5 + i
                  << std::endl;
      }
    }
  }
  return 0;
}
