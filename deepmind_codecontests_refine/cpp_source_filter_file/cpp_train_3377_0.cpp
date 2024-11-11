#include <bits/stdc++.h>
using namespace std;
char s[5];
int t[100100];
int who[100100];
vector<vector<int> > g;
int bad[100100];
set<int> now;
int was[100100];
vector<int> res;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  g.resize(n);
  for (int i = (0); i < (m); ++i) {
    scanf("%s%d", s, &who[i]);
    who[i]--;
    if (s[0] == '+') t[i] = 1;
    if (g[who[i]].size() == 0) {
      if (t[i] == 1) g[who[i]].push_back(-1);
    }
    g[who[i]].push_back(i);
  }
  for (int i = (0); i < (n); ++i) {
    if (g[i].size()) {
      int v = g[i].back();
      if (t[v] == 0) g[i].push_back(m);
    }
  }
  for (int i = (0); i < (n); ++i) {
    for (int j = 0; j < g[i].size(); j += 2) {
      int v1 = g[i][j];
      int v2 = g[i][j + 1];
      if (v2 - 1 > v1) bad[i] = 1;
    }
  }
  for (int i = (0); i < (m); ++i) {
    if (t[i] == 0) {
      if (was[who[i]]) continue;
      now.insert(i);
    } else {
      was[who[i]] = 1;
    }
  }
  for (int i = (0); i < (m); ++i) {
    if (t[i] == 0) now.erase(who[i]);
    if (now.size()) bad[who[i]] = 1;
    if (t[i] == 1) now.insert(who[i]);
  }
  for (int i = (0); i < (n); ++i) {
    if (bad[i] == 0) res.push_back(i + 1);
  }
  printf("%d\n", res.size());
  if (res.size()) {
    for (int i = (0); i < (res.size()); ++i) {
      if (i) printf(" ");
      printf("%d", res[i]);
    }
    printf("\n");
  }
}
