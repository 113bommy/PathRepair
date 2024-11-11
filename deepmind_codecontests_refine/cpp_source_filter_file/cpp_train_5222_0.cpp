#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, h;
  cin >> n >> m >> h;
  int a[n];
  for (int i = 0; i < n; i++) a[i] = h;
  for (int i = 0; i < m; i++) {
    int l, r, price;
    cin >> l >> r >> price;
    for (int j = l - 1; j < r; j++)
      if (a[j] > price) a[j] = price;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) sum += a[i] * a[i];
  cout << sum;
  return 0;
}
