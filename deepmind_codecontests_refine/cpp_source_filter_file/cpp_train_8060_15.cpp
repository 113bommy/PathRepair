#include <bits/stdc++.h>
using namespace std;
int main() {
  short n, k;
  cin >> n >> k;
  short a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  cout << a[n - k] << "\n";
  return 0;
}
