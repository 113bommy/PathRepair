#include <bits/stdc++.h>
using namespace std;
long long a[10], nd[10], dad[10], root, ans;
int nopd(long long n) {
  long long now = 2, ans = 0;
  for (; now * now <= n; now++)
    ;
  for (int i = 2; i <= now; i++)
    while (n && n % now == 0) {
      n /= now;
      ans++;
    }
  if (n > 1) ans++;
  return ans;
}
int main() {
  int n, best, ibest, flag;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  for (int i = 0; i < n; i++) {
    nd[i] = nopd(a[i]);
    ans += nd[i];
    if (nd[i] == 1) ans--;
  }
  for (int i = 0; i < n; i++) {
    if (!dad[i]) root++;
    flag = 1;
    while (flag) {
      best = ibest = -1;
      for (int j = i + 1; j < n; j++)
        if (a[i] % a[j] == 0 && !dad[j] && nd[j] > best) {
          best = nd[j];
          ibest = j;
        }
      if (ibest == -1)
        flag = 0;
      else {
        ans -= (best - 1);
        dad[ibest] = i + 1;
        a[i] /= a[ibest];
      }
    }
  }
  ans += root;
  if (root > 1) ans++;
  cout << ans << endl;
}
