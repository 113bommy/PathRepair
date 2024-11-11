#include <bits/stdc++.h>
using namespace std;
int a[1111], n, k = 1, q = 1;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater<int>());
  cout << a[0] << " ";
  for (int i = n - 2; i >= 1; i--) cout << a[i] << " ";
  cout << a[n - 1];
  return 0;
}
