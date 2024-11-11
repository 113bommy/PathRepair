#include <bits/stdc++.h>
int const N = 1e5 + 1;
using namespace std;
int main() {
  int q, n, a[N];
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 2) {
      cout << "0" << endl;
      continue;
    }
    sort(a, a + n);
    for (int i = n - 2; i > 0; i--) {
      int size = i;
      if (a[n - 2] >= size + 1) {
        cout << size << endl;
        break;
      }
      if (i == 1) cout << "0" << endl;
    }
  }
}
