#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int m = 0, n, c = 0, x, r, l, t;
  cin >> n;
  long long int a[n + 10];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> t;
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    c = 1;
    for (int j = i; j < n - 1; j++) {
      if (a[j + 1] - a[j] <= t) {
        c++;
      } else {
        break;
      }
    }
    m = max(m, c);
  }
  cout << m << endl;
}
