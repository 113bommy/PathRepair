#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, t;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  t = n / 2;
  if (n == 1)
    cout << a[0];
  else if (n == 2)
    cout << a[1];
  else if (n == 3)
    cout << a[1];
  else if (n % 2 == 0)
    cout << a[t - 1];
  else if (n % 2 == 1)
    cout << a[t];
}
