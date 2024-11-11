#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int64_t L;
  cin >> n >> L;
  vector<vector<int>> nxt(1, vector<int>(2, -1));
  vector<int> dep(1, 0);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0, x = 0; j < s.size(); ++j) {
      if (nxt[x][s[j] - '0'] == -1) {
        nxt[x][s[j] - '0'] = nxt.size();
        nxt.emplace_back(2, -1);
        dep.emplace_back(dep[x] + 1);
      }
      x = nxt[x][s[j] - '0'];
    }
  }
  int64_t res = 0;

  auto Grundy = [&](int64_t v) {
    if (v == 0) return 0LL;
    for (int i = 60; i >= 0; --i) {
      if (v % (1LL << i) == 0) return 1LL << i;
    }
  };

  for (int i = 0; i < nxt.size(); ++i) {
    if (nxt[i][0] == -1) res ^= Grundy(L - dep[i]);
    if (nxt[i][1] == -1) res ^= Grundy(L - dep[i]);
  }
  cout << (res > 0 ? "Alice" : "Bob") << "\n";
}
