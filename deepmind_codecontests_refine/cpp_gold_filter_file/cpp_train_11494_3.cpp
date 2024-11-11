#include <bits/stdc++.h>
using namespace std;
int a[100010], vis[100010];
int n;
void dfs(int x, int k) {
  if (k < 1) return;
  vis[x] = 1;
  a[k] = x;
  if (!vis[(x + n) / 2])
    dfs((x + n) / 2, k - 1);
  else
    dfs(x / 2, k - 1);
}
int main() {
  cin >> n;
  if (!(n & 1)) {
    dfs(0, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << a[n] << endl;
  } else
    puts("-1");
  return 0;
}
