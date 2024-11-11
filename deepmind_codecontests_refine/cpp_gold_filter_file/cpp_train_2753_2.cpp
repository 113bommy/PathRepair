#include <bits/stdc++.h>
using namespace std;
int n;
int p[122];
bool vis[12];
void output(vector<int> &s) {
  memset(vis, 0, sizeof vis);
  bool fst = 1;
  while (1) {
    int u = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (!vis[s[i]]) {
        u = s[i];
        vis[s[i]] = 1;
        break;
      }
    }
    if (u == -1) break;
    vector<int> t;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == u) t.push_back(i + 1);
    }
    if (fst)
      fst = 0;
    else
      putchar(',');
    printf("{");
    for (int i = 0; i < t.size(); ++i) {
      printf("%d%c", t[i], i == t.size() - 1 ? '}' : ',');
    }
  }
  puts("");
}
int main() {
  scanf("%d", &n);
  vector<vector<int> > x;
  vector<int> t;
  t.push_back(0);
  x.push_back(t);
  for (int i = 2; i <= n; ++i) {
    vector<vector<int> > y;
    for (int j = 0; j < x.size(); ++j) {
      int mx = 0;
      for (int k = 0; k < x[j].size(); ++k) {
        mx = max(mx, x[j][k]);
      }
      mx++;
      if (j % 2 == 0) {
        vector<int> t = x[j];
        t.push_back(0);
        y.push_back(t);
        for (int k = mx; k >= 1; --k) {
          t = x[j];
          t.push_back(k);
          y.push_back(t);
        }
      } else {
        vector<int> t = x[j];
        for (int k = 1; k <= mx; ++k) {
          t = x[j];
          t.push_back(k);
          y.push_back(t);
        }
        t = x[j];
        t.push_back(0);
        y.push_back(t);
      }
    }
    x = y;
  }
  printf("%d\n", (int)x.size());
  for (int i = 0; i < x.size(); ++i) {
    output(x[i]);
  }
  return 0;
}
