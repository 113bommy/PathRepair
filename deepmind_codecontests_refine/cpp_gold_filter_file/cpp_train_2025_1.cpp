#include <bits/stdc++.h>
using namespace std;
long long n, m = 0, i, j, a[100000], f = 0, d = 1, e = 0, c;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      f++;
      d = i;
    }
  }
  if (!f)
    cout << 0;
  else if (f > 1)
    cout << -1;
  else if (f == 1 && a[n - 1] <= a[0])
    cout << n - d - 1;
  else
    cout << -1;
}
