#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int c[n];
  int a[m];
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int j = 0; j < m; j++) cin >> a[j];
  int h = 0;
  int wyn = 0;
  for (int k = 0; k < n; k++) {
    if (c[k] <= a[h] && h < m) {
      wyn++;
      h++;
    }
  }
  cout << wyn;
}
