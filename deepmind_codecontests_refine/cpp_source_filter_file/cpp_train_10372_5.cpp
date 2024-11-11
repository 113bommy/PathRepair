#include <bits/stdc++.h>
using namespace std;
int p[100001], a[100001];
bool fix[100001];
long long n, i, j, na, k, x, ans;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> p[i];
  for (i = 1; i <= n; i++)
    if (fix[i] == 0) {
      j = i;
      k = 0;
      while (fix[j] == 0) {
        fix[j] = 1;
        k++;
        j = p[j];
      }
      na++;
      a[na] = k;
    }
  sort(a + 1, a + na + 1);
  if (na == 1)
    ans = n * n;
  else {
    ans = (a[na] + a[na - 1]) * (a[na] + a[na - 1]);
    for (i = 1; i < na - 1; i++) ans = ans + (a[i] * a[i]);
  }
  cout << ans << endl;
}
