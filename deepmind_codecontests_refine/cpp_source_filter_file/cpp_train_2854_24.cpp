#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k = 2;
  cin >> n;
  long long int a[n], b[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i < 2)
      b[i] = a[i];
    else
      b[i] = a[i - 1] + a[i - 2];
  }
  int x = 0, c[n];
  for (int i = 2; i < n; ++i) {
    if (a[i] == b[i])
      k++;
    else if (a[i] != b[i] && k) {
      c[x] = k;
      k = 2;
      x++;
    }
  }
  c[x] = k;
  x++;
  sort(c, c + x);
  if (x)
    cout << c[x - 1];
  else if (n == 1)
    cout << "1";
  else
    cout << k;
  return 0;
}
