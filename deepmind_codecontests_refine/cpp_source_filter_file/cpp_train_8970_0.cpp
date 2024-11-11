#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
int num[N][55], a[55];
int hsy[55];
int main() {
  int n, k, maxx = 0;
  scanf("%d %d", &n, &k);
  memset(num, -1, sizeof(num));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    maxx = max(maxx, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    int tmp = a[i], cnt = 0;
    while (true) {
      num[tmp][i] = cnt;
      if (tmp == 0) break;
      tmp /= 2;
      cnt++;
    }
  }
  int ans = inf;
  for (int i = 0; i <= maxx; i++) {
    int e = 1, tmp = 0;
    for (int j = 1; j <= n; j++) {
      if (num[i][j] != -1) hsy[e++] = num[i][j];
    }
    if (e >= k) {
      sort(hsy + 1, hsy + e);
      for (int i = 1; i <= k; i++) tmp += hsy[i];
      ans = min(ans, tmp);
    }
  }
  printf("%d\n", ans);
}
