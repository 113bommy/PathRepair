#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 9;
const long long mod = 987654323;
char str[maxn];
int mn, mx;
int n, k;
int vis[300];
void init() {
  scanf("%d%d%s", &n, &k, str);
  mn = 10000;
  mx = -1000;
  for (int i = 0; i < n; i++) {
    vis[str[i]] = 1;
    mn = min(mn, (int)str[i]);
    mx = max(mx, (int)str[i]);
  }
}
int main() {
  init();
  if (n < k) {
    printf("%s", str);
    for (int i = n; i < k; i++) {
      printf("%c", mn);
    }
    return 0;
  }
  int tmp = n - 1;
  while (str[tmp] == mx) tmp--;
  for (int i = 0; i < tmp; i++) {
    printf("%c", str[i]);
  }
  for (int i = str[tmp] + 1; i < 300; i++) {
    if (vis[i]) {
      printf("%c", i);
      break;
    }
  }
  for (int i = tmp + 1; i < k; i++) {
    printf("%c", mn);
  }
  return 0;
}
