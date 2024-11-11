#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 100;
int a[maxn];
int b[maxn];
int vis[maxn];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    vis[a[i]] = 1;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    vis[b[i]] = 1;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[a[i] ^ b[j]]) ans++;
    }
  }
  if (ans % 2)
    puts("Koyomi");
  else
    puts("Karen");
  return 0;
}
