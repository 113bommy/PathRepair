#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c, a[100000], k[100000];
  cin >> n >> m >> c;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> k[i];
  }
  for (int i = 0; i + m <= n; i++) {
    for (int j = 0, f = i; j < m; j++, f++) {
      a[f] += k[j];
      a[f] = a[f] % c;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
