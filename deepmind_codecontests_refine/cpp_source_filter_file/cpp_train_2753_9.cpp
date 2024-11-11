#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> vs[10];
int main() {
  int n;
  scanf("%d", &n);
  vs[1].push_back({0});
  for (int i = 2; i <= n; i++) {
    int u = 0;
    for (auto v : vs[i - 1]) {
      auto w = v;
      w.push_back(u);
      vs[i].push_back(w);
      int m = 0;
      for (auto k : v) {
        m = max(m, k);
      }
      for (int j = 2; j <= m + 1; j++) {
        w = v;
        w.push_back(j);
        vs[i].push_back(w);
      }
      u ^= 1;
      w = v;
      w.push_back(u);
      vs[i].push_back(w);
    }
  }
  printf("%d\n", (int)vs[n].size());
  for (auto v : vs[n]) {
    int m = 0;
    for (auto k : v) {
      m = max(m, k);
    }
    auto sp = "";
    for (int i = 0; i <= m; i++) {
      printf("%s{", sp);
      sp = ".";
      auto sp2 = "";
      for (int k = 0; k < v.size(); k++) {
        if (v[k] == i) {
          printf("%s%d", sp2, k + 1);
          sp2 = ".";
        }
      }
      printf("}");
    }
    puts("");
  }
  return 0;
}
