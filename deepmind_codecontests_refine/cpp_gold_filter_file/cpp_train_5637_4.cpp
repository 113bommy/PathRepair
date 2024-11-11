#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N], vis[N * N * 2 + 10];
int main() {
  int n;
  scanf("%d", &n);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    vis[a[i]] = 1;
  }
  sort(a + 1, a + n + 1);
  mx = a[n] + a[n - 1];
  int ans = 0;
  for (int i = 1; i <= mx; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      int v = i - a[j];
      if (v <= a[j]) break;
      cnt += vis[v];
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
