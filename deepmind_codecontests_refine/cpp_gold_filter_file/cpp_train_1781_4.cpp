#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, m, w, ans;
int a[600020], c[600020], num[600020], b[600020];
vector<int> vec[202];
char ch[20];
void init() {
  for (int i = 0; i <= (1 << w) - 1; ++i) {
    int x = 0;
    for (int j = w - 1; j >= 0; --j) {
      x = x * 3 + ((i >> j) & 1);
    }
    b[i] = x;
  }
  for (int i = 0; i <= (1 << w) - 1; ++i) {
    for (int j = 0; j <= (1 << w) - 1; ++j) {
      int x = b[i], y = b[j];
      num[x + y] += c[i] * c[j];
    }
  }
  vec['A'].push_back(0);
  vec['A'].push_back(1);
  vec['O'].push_back(0);
  vec['X'].push_back(0);
  vec['X'].push_back(2);
  vec['a'].push_back(2);
  vec['o'].push_back(1);
  vec['o'].push_back(2);
  vec['x'].push_back(1);
}
void dfs(int x, int d) {
  if (x == w + 1) {
    ans += num[d];
    return;
  }
  for (int i = 0; i < (int)vec[ch[x]].size(); ++i) {
    dfs(x + 1, d * 3 + vec[ch[x]][i]);
  }
}
int main() {
  scanf("%d %d %d", &w, &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), c[a[i]]++;
  init();
  while (m--) {
    scanf("%s", ch + 1);
    ans = 0, dfs(1, 0);
    printf("%d\n", ans);
  }
}
