#include <bits/stdc++.h>
const int MAXN = 100 + 5;
char ch[23];
std::multiset<std::string> S;
std::string str, ans;
int del[MAXN], tt[MAXN];
std::vector<std::string> SS;
int f[MAXN][26];
inline bool cmp(std::string a, std::string b) {
  return a.length() < b.length();
}
int main() {
  int n;
  scanf("%d", &n);
  if (n <= 3) {
    for (int i = 1; i <= n; ++i) {
      printf("? %d %d\n", i, i);
      std::fflush(stdout);
      scanf("%s", ch + 1);
      ans = ans + ch[1];
    }
    ans = "! " + ans;
    std::cout << ans << std::endl;
    std::fflush(stdout);
    return 0;
  }
  printf("? 1 %d\n", n / 2);
  std::fflush(stdout);
  for (int i = 1; i <= (n / 2) * (n / 2 + 1) / 2; ++i) {
    std::cin >> str;
    std::sort(str.begin(), str.end());
    S.insert(str);
  }
  printf("? 1 %d\n", n / 2 - 1);
  std::fflush(stdout);
  for (int i = 1; i <= (n / 2 - 1) * (n / 2) / 2; ++i) {
    std::cin >> str;
    std::sort(str.begin(), str.end());
    S.erase(S.find(str));
  }
  for (auto x : S) SS.push_back(x);
  std::sort(SS.begin(), SS.end(), cmp);
  for (auto x : SS) {
    for (int i = 0; i <= 25; ++i) tt[i] = del[i];
    char t;
    for (int i = 0; i <= (int)x.length() - 1; ++i) {
      if (!tt[x[i] - 'a']) t = x[i];
      tt[x[i] - 'a']--;
    }
    del[t - 'a']++;
    ans = t + ans;
  }
  printf("? %d %d\n", 1, n);
  std::fflush(stdout);
  for (int i = 1; i <= n * (n + 1) / 2; ++i) {
    std::cin >> str;
    for (int i = 0; i <= (int)str.length() - 1; ++i)
      f[str.length()][str[i] - 'a']++;
  }
  for (int i = n; i >= 1; --i) {
    int l = i, r = n - i + 1;
    if (l >= r) continue;
    for (int x = 0; x <= 25; ++x) {
      int t = f[i][x] - f[i - 1][x];
      for (int i = l; i <= r - 1; ++i)
        if (ans[i - 1] - 'a' == x) t--;
      if (t) {
        ans = ans + (char)(x + 'a');
        break;
      }
    }
  }
  ans = "! " + ans;
  std::cout << ans;
  std::fflush(stdout);
  return 0;
}
