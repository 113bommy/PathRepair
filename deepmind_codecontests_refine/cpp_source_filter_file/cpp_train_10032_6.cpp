#include <bits/stdc++.h>
using namespace std;
using namespace std;
using namespace std;
using namespace std;
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN], b[MAXN];
int main() {
  int m, n, i, j, k;
  ;
  scanf("%d", &m);
  for (i = 1; i <= m; i++) scanf("%d", &a[i]);
  for (i = 1; i <= m; i++) {
    b[a[i]] = 1;
    int now = a[i], o = 22;
    j = i - 1;
    while (o--) {
      if (j < 1) break;
      now = now | a[j];
      b[now] = 1;
      j--;
    }
  }
  int ans = 0;
  for (i = 0; i <= 1000000; i++)
    if (b[i]) ans++;
  cout << ans << endl;
}
