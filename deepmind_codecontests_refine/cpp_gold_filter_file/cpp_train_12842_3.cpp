#include <bits/stdc++.h>
using namespace std;
int a[1000000 + 2];
int main() {
  int p, b, k;
  cin >> p >> b >> k;
  for (int i = 2; i <= 1000; i++) {
    if (a[i]) continue;
    for (int j = i * i; j <= 1000000; j += i) a[j] = 1;
  }
  a[1] = 1;
  int ans = 0, t = 0, o = p;
  for (int i = p; i <= b; i++) {
    if (t >= k) {
      if (!a[o]) t--;
      if (!a[i]) t++;
      if (t < k)
        t++, ans++;
      else
        o++;
    } else {
      ans++;
      if (!a[i]) t++;
    }
  }
  if (k > t)
    cout << -1;
  else
    cout << ans;
}
