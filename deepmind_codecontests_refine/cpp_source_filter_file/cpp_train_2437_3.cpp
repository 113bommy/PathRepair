#include <bits/stdc++.h>
using namespace std;
int a[1111], n, k = 1, q = 1;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n, greater<int>());
  cout << a[1] << " ";
  for (int i = n - 1; i >= 2; i--) cout << a[i] << " ";
  cout << a[n];
  return 0;
}
