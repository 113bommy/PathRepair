#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[110], x[110], k = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) x[i] = a[n - 1] - a[i];
  for (int i = 0; i < n; i++) k = k + x[i];
  cout << k;
}
