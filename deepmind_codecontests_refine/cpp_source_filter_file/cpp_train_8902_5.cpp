#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int mod = 11092019;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
char s[MAXN];
int a[MAXN], vis[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int p = 1;
  vis[1] = 1;
  while (1) {
    if (s[p] == '>') {
      if (p + a[p] > n) {
        printf("FINITE\n");
        break;
      } else if (vis[p + a[p]]) {
        printf("INFINITE\n");
        break;
      } else {
        vis[p + a[p]] = 1;
        p = p + a[p];
      }
    } else {
      if (p - a[p] < 1) {
        printf("FINITE\n");
        break;
      } else if (vis[p - a[p]]) {
        printf("INFINITE\n");
        break;
      } else {
        vis[p + a[p]] = 1;
        p = p + a[p];
      }
    }
  }
  return 0;
}
