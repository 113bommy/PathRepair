#include <bits/stdc++.h>
using namespace std;
int n, a[999999], d1, d2, d3;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) d1++;
    if (a[i] == 2) d2++;
    if (a[i] == 3) d3++;
  }
  int res = max(max(d1, d2), d3);
  cout << n - res;
}
