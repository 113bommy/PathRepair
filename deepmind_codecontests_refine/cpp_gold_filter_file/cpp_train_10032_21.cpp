#include <bits/stdc++.h>
using namespace std;
using namespace std;
using namespace std;
using namespace std;
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN], b[MAXN << 2];
int main() {
  int m, n, i, j, k;
  ;
  scanf("%d", &m);
  for (i = 1; i <= m; i++) scanf("%d", &a[i]);
  for (i = 1; i <= m; i++) {
    b[a[i]] = 1;
    int now = 0;
    for (j = i - 1; j >= 1; j--) {
      now |= a[j];
      b[now | a[i]] = 1;
      if (!(a[i] & ~now)) break;
    }
  }
  int ans = 0;
  for (i = 0; i <= 4000000; i++)
    if (b[i]) ans++;
  cout << ans << endl;
}
