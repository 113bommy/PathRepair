#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0;
  cin >> n;
  char a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= 65 && a[i] <= 90) {
      a[i] = 97 + a[i] - 65;
    }
  }
  sort(a, a + n);
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1]) {
      c++;
    }
  }
  if (c >= 25)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
