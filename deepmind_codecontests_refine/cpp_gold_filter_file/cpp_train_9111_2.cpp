#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
const int M = 2e6 + 7;
const int lim = 2e6;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
int a[N], num[N];
bool vis[N];
void init() {
  vis[1] = 1;
  for (register int i = 2; i <= lim; i++)
    if (vis[i] == 0)
      for (register int j = i + i; j <= lim; j += i) vis[j] = 1;
}
int main() {
  init();
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    num[a[i]]++;
  }
  if (num[1] > 1) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (vis[a[i] + 1] == 0 && a[i] != 1) {
        ans = i;
        break;
      }
    }
    printf("%d\n", num[1] + (ans > 0 ? 1 : 0));
    for (int i = 1; i <= num[1]; i++) printf("1 ");
    if (ans > 0) printf("%d\n", a[ans]);
  } else {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (vis[a[i] + a[j]] == 0) {
          printf("2\n%d %d\n", a[i], a[j]);
          return 0;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (vis[a[i]] == 0) {
        printf("1\n%d\n", a[i]);
        return 0;
      }
    }
    printf("1\n%d\n", a[1]);
  }
  return 0;
}
