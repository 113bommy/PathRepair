#include <bits/stdc++.h>
using namespace std;
int f[111111];
int vis[111111];
int ans[111111];
int num[111111];
int maxnum[111111];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }
  for (int i = 1; i <= 100000; i++) vis[i] = 1;
  for (int i = 1; i <= n; i++) {
    ans[i] = vis[f[i]]++;
    num[ans[i]]++;
    maxnum[ans[i]] = max(maxnum[ans[i]], f[i]);
  }
  int box_num = 1;
  for (int i = 1; i <= n; i++) box_num = max(box_num, ans[i]);
  for (int i = 1; i <= box_num; i++) {
    if (num[i] != maxnum[i]) {
      printf("-1\n");
      return 0;
    }
  }
  printf("%d\n", box_num);
  for (int i = 1; i <= box_num; i++) printf("%d ", ans[i]);
  return 0;
}
