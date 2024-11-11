#include <bits/stdc++.h>
using namespace std;
int n;
int vis[108];
int cnt = 0;
int ans = 0;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    if (a != 0) {
      if (!vis[a]) {
        vis[a] = 1;
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
