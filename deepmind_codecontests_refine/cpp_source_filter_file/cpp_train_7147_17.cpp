#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 5;
int a[MAXN];
int c[MAXN];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int temp;
    scanf("%d", &temp);
    if (temp) {
      ans += a[i];
      c[i] = c[i - 1];
    } else {
      c[i] = c[i - 1] + a[i];
    }
  }
  int mm = 0;
  for (int i = n; i > k; i--) {
    mm = max(c[i] - c[i - k], mm);
  }
  ans += mm;
  cout << ans << endl;
  return 0;
}
