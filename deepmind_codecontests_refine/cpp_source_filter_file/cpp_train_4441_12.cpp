#include <bits/stdc++.h>
const int N = 1e5 + 7;
const int inf = 0x3f3f3f3f;
using namespace std;
vector<int> stk[N];
int dep[N];
void dfs(int num, int height) {
  dep[height]++;
  for (int i = 0; i < stk[num].size(); i++) {
    int v = stk[num][i];
    dfs(v, height + 1);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    stk[x].push_back(i);
  }
  dfs(1, 1);
  int ans = 0;
  for (int i = 1; i < n; i++) ans += dep[i] % 2;
  printf("%d\n", ans);
  return 0;
}
