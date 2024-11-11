#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int odd = 0;
  int even = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2)
      odd++;
    else
      even++;
  }
  int x = min(odd, even);
  odd = odd - x;
  x = x + (odd / 3);
  cout << x << endl;
  return 0;
}
