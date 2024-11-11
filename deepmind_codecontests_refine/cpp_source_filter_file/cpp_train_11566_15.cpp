#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 0, b, c = 0;
  cin >> n;
  int a[1000];
  for (int i = 0; i < n; i++) {
    cin >> b;
    if (b == 1) {
      a[m] = c;
      m += 1;
    }
    c = b;
  }
  a[m] = c;
  cout << m << endl;
  for (int i = 1; i < m + 1; i++) {
    cout << a[i];
  }
  return 0;
}
