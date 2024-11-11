#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  int a[100000];
  long long k, min = 2000000000;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (min > a[i]) min = a[i];
  }
  int z = 0, d = 0;
  for (int i = 0; i < n; i++) {
    if ((a[i] - min) % k == 0)
      d += (a[i] - min);
    else {
      z = -1;
      break;
    }
  }
  if (z == -1)
    cout << -1;
  else
    cout << d / k;
}
