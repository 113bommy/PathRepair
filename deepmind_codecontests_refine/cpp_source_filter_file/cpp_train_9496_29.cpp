#include <bits/stdc++.h>
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; c > '9' || c < '0'; c = getchar()) {
    if (c == '-') f = -1;
  }
  for (; c >= '0' && c <= '9'; c = getchar()) {
    x = x * 10 + c - '0';
  }
  return x * f;
}
int cnt[27][105];
char s[105], s1[105];
std::string sss, halfans, halfans2;
std::vector<char> ans;
std::map<std::string, int> H1[105], H2[105];
inline char getA(std::string a, std::string b) {
  int c[30];
  memset(c, 0, sizeof c);
  for (int i = 0; i < a.size(); i++) c[a[i] - 'a']++;
  for (int i = 0; i < b.size(); i++) c[b[i] - 'a']--;
  for (int i = 0; i < 26; i++) {
    if (c[i] > '0') return i + 'a';
  }
  return 'a';
}
inline std::string solve(int n) {
  printf("? 1 %d\n", n);
  fflush(stdout);
  for (int i = 1; i <= n * (n + 1) >> 1; i++) {
    scanf("%s", s);
    sss = std::string(s);
    std::sort(sss.begin(), sss.end());
    H1[sss.size()][sss]++;
  }
  printf("> 2 %d\n", n);
  fflush(stdout);
  for (int i = 1; i <= n * (n - 1) >> 1; i++) {
    scanf("%s", s);
    sss = std::string(s);
    std::sort(sss.begin(), sss.end());
    H2[sss.size()][sss]++;
  }
  for (int i = 1; i <= n; i++) {
    for (auto p : H2[i]) {
      H1[i][p.first] -= H2[i][p.first];
    }
    for (auto p : H1[i]) {
      if (p.second > 0) {
        std::string new1 = ("");
        for (int j = 0; j < ans.size(); j++) new1 += ans[j];
        ans.push_back(getA(p.first, new1));
      }
    }
  }
  std::string new1 = ("");
  for (int j = 0; j < ans.size(); j++) new1 += ans[j];
  return new1;
}
inline void work() {
  int n = read();
  if (n == 1) {
    puts("? 1 1");
    fflush(stdout);
    scanf("%s", s);
    printf("! %s\n", s);
    fflush(stdout);
  } else if (n == 2) {
    puts("? 1 1");
    fflush(stdout);
    scanf("%s", s);
    puts("? 2 2");
    fflush(stdout);
    scanf("%s", s1);
    printf("! %s%s\n", s, s1);
    fflush(stdout);
  } else {
    halfans = solve(n + 1 >> 1);
    printf("? 1 %d\n", n);
    fflush(stdout);
    for (int i = 1; i <= n * (n + 1) >> 1; i++) {
      scanf("%s", s);
      sss = std::string(s);
      for (int j = 0; j < sss.size(); j++) {
        cnt[sss[j] - 'a'][sss.size()]++;
      }
    }
    halfans2 = std::string("");
    for (int i = 1; i <= n >> 1; i++) {
      for (int j = 0; j < 26; j++) {
        int num = cnt[j][1] - (cnt[j][i + 1] - cnt[j][i]);
        for (int k = 0; k < i; k++) {
          if (halfans[k] - 'a' == j) {
            num--;
          }
        }
        for (int k = 0; k < halfans2.size(); k++) {
          if (halfans2[k] - 'a' == j) {
            num--;
          }
        }
        if (num > 0) {
          halfans2 += ('a' + j);
          break;
        }
      }
    }
    for (int i = halfans2.size() - 1; ~i; i--) halfans += halfans2[i];
    printf("! %s\n", halfans.c_str());
    fflush(stdout);
  }
}
int main() {
  work();
  return 0;
}
