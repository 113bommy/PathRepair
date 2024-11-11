#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int t, q, book, n;
int w[maxn];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    memset(w, 0, sizeof(w));
    book = 0;
    for (int i = 0; i < n; i++) {
      cin >> q;
      w[q - 1]++;
    }
    sort(w, w + n);
    for (int i = 0; i < n; i++) {
      if (w[i] == 0) {
        book++;
      }
    }
    if (n == 1) {
      cout << 0 << endl;
    } else if (n - book == 1) {
      cout << 1 << endl;
    } else if (w[n - 1] > n - book) {
      cout << n - book << endl;
    } else if (w[n - 1] == n - book) {
      cout << n - book - 1 << endl;
    } else {
      cout << w[n - 1] << endl;
    }
  }
}
