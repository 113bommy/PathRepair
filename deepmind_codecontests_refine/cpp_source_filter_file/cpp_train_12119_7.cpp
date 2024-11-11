#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
int i, j, k, l, m, n, o, p, Max, ans, a[N], b[N];
int main() {
  scanf("%d", &n);
  for (i = 0; i <= n - 1; i++) {
    scanf("%d", &a[i]);
    b[a[i]] = i;
  }
  for (i = 0; i <= n - 1; i++) {
    ans += (a[i] == i);
  }
  Max = ans;
  for (i = 0; i <= n - 1; i++)
    if (a[i] != i) {
      o = b[i];
      p = 1;
      if (i == a[o]) p++;
      Max = max(Max, ans + p);
    }
  cout << Max << endl;
  return 0;
}
