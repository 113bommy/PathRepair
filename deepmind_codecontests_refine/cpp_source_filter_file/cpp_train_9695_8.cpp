#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100], c = 0, i, j;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = 0, j = i + 1; i < n, j < n; i++, j++) {
    c += a[j] - a[i];
  }
  cout << c;
  return 0;
}
