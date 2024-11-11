#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int m;
  cin >> m;
  int b[m];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(b, b + n);
  int pairs = 0;
  for (int i = 0, j = 0; i < n, j < m;) {
    if (abs(a[i] - b[j]) <= 1) {
      pairs++;
      i++;
      j++;
    } else if (a[i] > b[j])
      j++;
    else if (b[j] > a[i])
      i++;
  }
  cout << pairs << '\n';
  return 0;
}
