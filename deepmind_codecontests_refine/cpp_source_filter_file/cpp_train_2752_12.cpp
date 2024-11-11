#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, c = 0, d = 0, l = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 0 && l >= 10) {
      c += a[i];
      l += a[i];
    } else if (a[i] == -1 && c > 0)
      c--;
    else
      d++;
  }
  cout << d << endl;
}
