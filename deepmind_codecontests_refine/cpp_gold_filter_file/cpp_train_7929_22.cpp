#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int a[100];
  int b[100];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b, b + m);
  cout << a[n - 1] << " " << b[m - 1];
  return 0;
}
