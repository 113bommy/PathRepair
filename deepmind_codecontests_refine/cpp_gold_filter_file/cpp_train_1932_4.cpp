#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300030;
int arr[MAXN];
int vis[MAXN];
int read[MAXN];
int book[MAXN];
int main() {
  int n, q, type, x;
  scanf("%d%d", &n, &q);
  int ans = 0;
  int len = 1;
  int f = 0;
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &type, &x);
    if (type == 1) {
      ans++;
      book[x]++;
      arr[len++] = x;
    } else if (type == 2) {
      vis[x] = len;
      ans -= book[x];
      book[x] = 0;
    } else if (type == 3) {
      if (x > f) {
        for (int j = f + 1; j <= x; j++) {
          if (j >= vis[arr[j]]) {
            ans--;
            book[arr[j]]--;
          }
        }
        f = x;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
