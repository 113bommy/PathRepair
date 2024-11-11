#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0;
  int n;
  cin >> n;
  int m = n;
  int a[n / 2];
  for (int i = 0; i < n / 2; i++) {
    cin >> a[i];
  }
  sort(a, a + n / 2);
  for (int i = n / 2 - 1; i >= 0; i--) {
    c = c + abs(m - a[i] - 1);
    m = m - 2;
  }
  m = n;
  int c1 = 0;
  for (int i = n / 2 - 1; i >= 0; i--) {
    c1 = c1 + abs(m - a[i]);
    m = m - 2;
  }
  cout << min(c, c1);
  return 0;
}
