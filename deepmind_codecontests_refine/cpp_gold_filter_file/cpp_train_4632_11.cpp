#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, i, j = 0, k, s, t = 0, l = 0, r = 0, p;
  cin >> n >> k >> p >> s >> y;
  int a[n], b[n - k];
  for (i = 0; i < k; i++) {
    cin >> a[i];
    s = s - a[i];
    if (a[i] == y) t = y;
    if (a[i] > y) r++;
    if (a[i] < y) l++;
  }
  for (i = 0; i < n - k; i++) b[i] = y;
  if (s < n - k)
    cout << "-1";
  else {
    i = 0;
    k = n - k;
    t = k * y;
    while (t > s && i < k) {
      while (b[i] != 1 && t > s) b[i]--, t--;
      i++;
    }
    if (i == k && t > s) {
      cout << "-1";
      return 0;
    }
    for (i = n - k; i < n; i++) a[i] = b[i + k - n];
    sort(a, a + n);
    if (a[(n) / 2] >= y)
      for (i = 0; i < k; i++) cout << b[i] << " ";
    else
      cout << "-1";
  }
  return 0;
}
