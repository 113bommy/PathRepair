#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long inf = 1000001;
int q, n, k, a[N], c, kol;
int main() {
  cin >> q;
  while (q--) {
    cin >> n >> k;
    int j = 1;
    kol = 0;
    for (int i = 1; i <= n; i++) {
      cin >> c;
      if (c % 2 == 1) {
        kol += 1;
        if (kol <= k) a[j++] = i;
      }
    }
    if (kol >= k && (kol - k) % 2 == 0) {
      cout << "YES" << endl;
      for (int i = 1; i < k; i++) {
        cout << a[i] << " ";
      }
      cout << n;
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
