#include <bits/stdc++.h>
using namespace std;
int n;
int p[200000 + 5];
int c[200000 + 5];
vector<int> cycles[200000 + 5];
int cycles_sz = 0;
bool visit[200000 + 5];
void dfs(int cur) {
  visit[cur] = true;
  cycles[cycles_sz].push_back(cur);
  if (!visit[p[cur]]) dfs(p[cur]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; ++tc) {
    int ans = 2147483647;
    for (int i = 0; i < cycles_sz; ++i) cycles[i].clear();
    cycles_sz = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &c[i]);
      visit[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      if (!visit[i]) {
        dfs(i);
        cycles_sz++;
      }
    }
    for (int i = 0; i < cycles_sz; ++i) {
      if ((int)cycles[i].size() < ans) ans = (int)cycles[i].size();
      for (int j = 2; j <= ((int)cycles[i].size() / 2) && j < ans; ++j) {
        if (cycles[i].size() % j == 0) {
          for (int k = 0; k < j; ++k) {
            bool valid = true;
            int cur = k;
            int target_color = c[cycles[i][k]];
            cur = (cur + j) % (cycles[i].size());
            while (cur != k) {
              if (c[cycles[i][cur]] != target_color) {
                valid = false;
                break;
              }
              cur = (cur + j) % (cycles[i].size());
            }
            if (valid) {
              if (j < ans) ans = j;
            }
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
