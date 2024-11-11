#include <bits/stdc++.h>
using namespace std;
long long a[150000], b[150000], n, p, mn, mx;
int main() {
  cin >> n;
  mn = 2147483647;
  mx = -2147483647;
  for (int i = 0; i < n; i++)
    cin >> a[i], mn = min(mn, a[i]), mx = max(mx, a[i]);
  if (mn == mx) {
    if (mx == 0) {
      puts("YES");
      for (int i = 0; i < n; i++) cout << 1 << ' ';
      cout << endl;
      return 0;
    } else
      return puts("NO"), 0;
  }
  for (int i = 0; i < n; i++)
    if (mx != a[(i - 1 + n) % n] && mx == a[i]) p = i;
  b[p] = a[p];
  for (int i = (p - 1 + n) % n; i != p; i = (i - 1 + n) % n)
    if (i == (p - 1 + n) % n)
      b[i] = a[i] + b[(i + 1) % n] * 2;
    else
      b[i] = a[i] + b[(i + 1) % n];
  puts("YES");
  for (int i = 0; i < n; i++) cout << b[i] << ' ';
  cout << endl;
}
