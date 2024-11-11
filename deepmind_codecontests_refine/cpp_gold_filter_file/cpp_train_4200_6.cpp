#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> a(n);
  vector<int> b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int k, rb = 0, ra = 0;
  vector<int> ansa(0);
  vector<int> ansb(0);
  while (rb < m && ra < n) {
    while (rb < m && a[ra] - x > b[rb]) rb++;
    if (rb == m) break;
    if (a[ra] + y >= b[rb]) {
      ansa.push_back(ra + 1);
      ansb.push_back(rb + 1);
      rb++;
    }
    ra++;
  }
  k = ansa.size();
  cout << k << endl;
  for (int i = 0; i < k; i++) cout << ansa[i] << " " << ansb[i] << endl;
}
