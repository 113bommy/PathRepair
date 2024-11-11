#include <bits/stdc++.h>
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    int n, m;
    scanf("%d", &n);
    std::map<std::string, int> mapping;
    for (int i = 0; i < n; ++i) {
      static char buffer[100 + 1];
      scanf("%s", buffer);
      mapping[buffer] = i;
    }
    scanf("%d", &m);
    getchar();
    std::vector<std::string> raw_string(m);
    std::vector<int> talker(m, -1);
    std::vector<std::vector<int>> ban(m);
    for (int i = 0; i < m; ++i) {
      static char buffer[100 + 1];
      gets(buffer);
      raw_string[i] = buffer;
      if (buffer[0] != '?') {
        talker[i] = mapping[raw_string[i].substr(0, raw_string[i].find(":"))];
      }
      for (int j = 0; buffer[j]; ++j) {
        if (std::string(".,!? ").find(buffer[j]) != std::string::npos)
          buffer[j] = ' ';
      }
      for (auto token : [&](std::string s) {
             std::vector<std::string> ret;
             for (int i = 0, j = 0; i <= s.size(); ++i) {
               if (i == s.size() || s[i] == ' ') {
                 ret.emplace_back(s.substr(j, i - j));
                 j = i + 1;
               }
             }
             return ret;
           }(buffer)) {
        if (mapping.find(token) != mapping.end())
          ban[i].emplace_back(mapping[token]);
      }
    }
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
    auto ok = [&](int i, int x) {
      return talker[i] == x ||
             talker[i] == -1 &&
                 std::find(ban[i].begin(), ban[i].end(), x) == ban[i].end();
    };
    for (int i = 0; i < n; ++i) {
      if (ok(0, i)) dp[0][i] = 0;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j)
        if (ok(i, j)) {
          for (int k = 0; k < n; ++k)
            if (k != j && dp[i - 1][k] != -1) {
              dp[i][j] = k;
              break;
            }
        }
    }
    int w = -1;
    for (int i = 0; i < n; ++i)
      if (dp[m - 1][i] != -1) w = i;
    if (w == -1) {
      puts("Impossible");
    } else {
      for (int i = m - 1; i >= 0; --i) {
        talker[i] = w;
        assert(dp[i][w] != -1);
        w = dp[i][w];
      }
      for (int i = 0; i < m; ++i) {
        for (auto x : mapping) {
          if (talker[i] == x.second) {
            printf("%s", x.first.c_str());
          }
        }
        printf("%s\n", raw_string[i].substr(raw_string[i].find(":")).c_str());
      }
    }
  }
}
