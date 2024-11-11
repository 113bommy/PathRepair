#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, a[200];
  cin >> q;
  while (q--) {
    int n, head = -1, tail = -1, sort = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) head = i;
      if (a[i] == n) tail = i;
    }
    if (a[(head + 1) % n] == a[tail]) {
      for (int i = 1; i < n; i++) {
        if (a[(head - i + n) % n] < a[(head - i - n + 1) % n]) {
          sort = 0;
          break;
        }
      }
    } else {
      for (int i = 1; i < n; i++) {
        if (a[(head + i) % n] < a[(head + i - 1) % n]) {
          sort = 0;
          break;
        }
      }
    }
    if (sort == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
