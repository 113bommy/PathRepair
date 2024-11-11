#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = a[i] % 3;
  }
  int c0 = 0, c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0)
      c0++;
    else if (a[i] == 1)
      c1++;
    else
      c2++;
  }
  int ans = c0 / 2 + min(c1, c2);
  cout << ans;
  return 0;
}
