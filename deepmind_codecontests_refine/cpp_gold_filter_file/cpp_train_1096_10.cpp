#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int LEN = 100 + 10;
int a[LEN];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int pa, pb;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) pa = i + 1;
      if (a[i] == n) pb = i + 1;
    }
    int xa = min(pa - 1, n - pa);
    int xb = min(pb - 1, n - pb);
    cout << n - 1 - min(xa, xb) << endl;
  }
  return 0;
}
