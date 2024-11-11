#include <bits/stdc++.h>
using namespace std;
int a[300001];
bool vis[300001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  printf("1 ");
  int last = n, cnt = 0;
  for (int i = 1; i <= n; i++) {
    vis[a[i]] = 1;
    while (last) {
      if (!vis[last]) break;
      last--;
      cnt++;
    }
    printf("%d ", i - cnt);
  }
  puts("");
  return 0;
}
