#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[101], n, k = 0, i;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = 0; i < n - 1; i++) {
    if (a[i] && a[i] == a[i + 1]) {
      k++;
      a[i + 1] = 0;
    }
  }
  cout << k / 2;
  return 0;
}
