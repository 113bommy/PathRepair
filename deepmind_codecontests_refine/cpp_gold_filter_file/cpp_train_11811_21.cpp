#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  sort(a, a + n - 1);
  for (i = 0; i < n - 1; i++) {
    if (a[i] != i + 1) {
      cout << i + 1 << endl;
      break;
    } else
      c++;
  }
  if (c == n - 1) cout << n << endl;
  return 0;
}
