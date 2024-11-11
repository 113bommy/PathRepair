#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a[1000], i, max1, maxf, ta, n, t, h[1000], c[1000], x;
  cin >> ta;
  while (ta-- > 0) {
    maxf = 0;
    max1 = 0;
    cin >> n;
    cin >> x;
    for (i = 0; i < n; i++) cin >> a[i], cin >> h[i];
    for (i = 0; i < n; i++) {
      c[i] = a[i] - h[i];
      if (maxf < a[i]) maxf = a[i];
      if (c[i] > max1) max1 = c[i];
    }
    sort(c, c + n);
    if (maxf > x)
      cout << "1" << endl;
    else if (c[n - 1] <= 0)
      cout << "-1" << endl;
    else {
      t = (x - maxf) / max1;
      if ((x - maxf) % max1 == 0)
        cout << t + 1 << endl;
      else
        cout << t + 2 << endl;
    }
  }
}
