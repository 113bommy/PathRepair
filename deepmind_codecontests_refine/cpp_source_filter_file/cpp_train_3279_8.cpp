#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, a[MAXN], b[MAXN];
bool vis[MAXN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int x = 0, y;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      int j = i, len = 0, h = 0;
      while (!vis[j]) {
        vis[j] = 1;
        len++;
        b[j] = h;
        h = 1 - h;
        j = a[j];
      }
      if (len == 1)
        x = 1, y = i;
      else if (len == 2 && x != -1 && x != 1)
        x = 2, y = i;
      else if (len % 2 == 1 && x != -1)
        x = -1;
    }
  }
  if (x <= 0) {
    cout << "NO" << endl;
    return 0;
  }
  if (x <= 0) {
    printf("NO");
    return 0;
  }
  if (x == 1) {
    printf("YES\n");
    for (int i = 1; i <= n; i++)
      if (i != y) printf("%d %d\n", i, y);
  } else {
    printf("YES\n%d %d\n", y, a[y]);
    for (int i = 1; i <= n; i++)
      if (i != y && i != a[y]) printf("%d %d\n", i, b[i] ? y : a[y]);
  }
  return 0;
}
