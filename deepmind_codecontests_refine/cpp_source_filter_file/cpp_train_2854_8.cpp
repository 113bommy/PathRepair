#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, i, j, c, d, m;
  cin >> n;
  long long a[n];
  if (n == 1) {
    cin >> a[0];
    cout << 1 << endl;
  } else if (n == 2) {
    cin >> a[0] >> a[1];
    cout << 2 << endl;
  } else {
    c = 2;
    m = 2;
    cin >> a[0] >> a[1];
    for (i = 2; i < n; i++) {
      cin >> a[i];
      if (a[i] == a[i - 1] + a[i - 2])
        c++;
      else {
        if (c >= m) m = c;
        c = 2;
      }
    }
    cout << c << endl;
  }
  return 0;
}
