#include <bits/stdc++.h>
using namespace std;
int n, a[1000005], k, t, ans;
bool u[1000005];
int main() {
  cin >> n;
  for (int i = n; i >= 0; i--)
    if (!u[i]) {
      k = log2(i) + 1;
      t = (1 << k) - 1;
      ans += t * 2;
      t -= i;
      a[i] = t;
      a[t] = i;
      u[t] = 1;
    }
  cout << ans << endl;
  for (int i = 0; i <= n; i++) cout << a[i] << " ";
}
