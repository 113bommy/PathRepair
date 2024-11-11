#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int n, l;
bool cmp(int e1, int e2) { return e1 > e2; }
int main() {
  int i, j, k, temp;
  int ans;
  while (scanf("%d%d", &n, &l) != EOF) {
    memset(a, 0, sizeof(a));
    ans = 0;
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n, cmp);
    for (j = l; j <= a[0]; j++) {
      temp = 0;
      for (i = 0; i < n; i++) {
        if (a[i] >= j)
          temp += a[i] / j;
        else
          break;
      }
      if (ans < temp * j) ans = temp * j;
    }
    cout << ans << endl;
  }
  return 0;
}
