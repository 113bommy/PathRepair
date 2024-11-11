#include <bits/stdc++.h>
using namespace std;
long long a[100001], b[100001], c[200002];
;
int main() {
  int n, i, k1;
  cin >> n;
  if (n == 1) {
    cin >> a[1] >> b[1];
    if (a[1] < b[1]) {
      cout << 1 << endl;
      cout << 0;
    } else {
      cout << 0 << endl;
      cout << 1;
    }
  } else {
    k1 = n / 2;
    int j = 1;
    for (i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      c[j] = a[i];
      c[j + 1] = b[i];
      j += 2;
    }
    sort(c + 1, c + 2 * n + 1);
    int max = c[n];
    for (i = 1; i <= n; i++) {
      if (i <= k1)
        cout << "1";
      else if (a[i] <= max)
        cout << 1;
      else
        cout << 0;
    }
    cout << endl;
    for (i = 1; i <= n; i++) {
      if (i <= k1)
        cout << "1";
      else if (b[i] <= max)
        cout << 1;
      else
        cout << 0;
    }
  }
}
