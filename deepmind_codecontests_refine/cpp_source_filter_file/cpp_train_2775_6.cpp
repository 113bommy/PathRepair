#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<vector<int>> g(N);
bool isDeleted[N];
vector<int> res;
void del(int s, int p) {
  res.push_back(s);
  isDeleted[s] = true;
  for (auto I : g[s]) {
    if (!isDeleted[N] && I != p) {
      del(I, s);
    }
  }
}
bool dfs(int s, int p) {
  int siz = g[s].size();
  for (auto I : g[s]) {
    if (I != p) {
      bool isDeleted = dfs(I, s);
      if (isDeleted) {
        --siz;
      }
    }
  }
  if (siz % 2 == 0) {
    del(s, p);
    return true;
  } else
    return false;
}
int main() {
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (x) {
      g[i].push_back(x - 1);
      g[x - 1].push_back(i);
    }
  }
  bool ans = dfs(0, -1);
  if (ans) {
    printf("YES\n");
    for (auto I : res) {
      printf("%d\n", I + 1);
    }
  } else
    printf("NO\n");
  return 0;
}
