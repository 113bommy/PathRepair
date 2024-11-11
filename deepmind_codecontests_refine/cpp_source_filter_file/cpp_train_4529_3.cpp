#include <bits/stdc++.h>
using namespace std;
int n, k;
const int maxn = 300000 + 500;
const int maxk = 5005;
const int INF = 2e9 + 100;
int a[maxn];
int d[maxk][maxk];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int large = n % k;
  int small = k - large;
  int seg = n / k;
  sort(a + 1, a + n);
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= k; j++) d[i][j] = INF;
  d[0][0] = 0;
  for (int i = 0; i <= large; i++) {
    for (int j = 0; j <= small; j++) {
      int nxt = i * (seg + 1) + j * seg + 1;
      if (i < large) {
        int add = a[nxt + seg] - a[nxt];
        d[i + 1][j] = min(d[i + 1][j], d[i][j] + add);
      }
      if (j < small) {
        int add = a[nxt + seg - 1] - a[nxt];
        d[i][j + 1] = min(d[i][j + 1], d[i][j] + add);
      }
    }
  }
  cout << d[large][small] << endl;
  return 0;
}
