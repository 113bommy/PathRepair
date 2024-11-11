#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t = 0, f = 0;
  cin >> n;
  int a[n + 1];
  for (int k = 1; k <= n; k++) {
    cin >> a[k];
    if (a[k] % 2 == 0 || n == 1) t++;
    if (a[k] % 2 != 0) f++;
  }
  if (f % 2 != 0)
    cout << 1;
  else
    cout << t;
}
