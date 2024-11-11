#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  long long c = 0, x = 0;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    if (a[i] == 1)
      x++;
    else
      c += x;
  }
  cout << x << endl;
  return 0;
}
