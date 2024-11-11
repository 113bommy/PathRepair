#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[5100], b[5100], p[5100], c[5100], a1[5100];
  int n, k = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "? " << i << " " << 0 << endl;
    fflush(stdout);
    cin >> a[i];
    cout << "? " << 0 << " " << i << endl;
    fflush(stdout);
    cin >> b[i];
  }
  int p0, u;
  for (int i = 0; i < n; i++) {
    p0 = a[0] ^ i;
    u = 0;
    for (int j = 0; j < n; j++) {
      p[j] = (a[j] ^ i);
      c[p[j]] = j;
    }
    if (c[0] != i) continue;
    for (int j = 1; j < n; j++) {
      if (c[j] != (b[j] ^ p0)) {
        u = 1;
      }
    }
    if (!u) {
      k++;
      for (int j = 0; j < n; j++) a1[j] = p[j];
    }
  }
  cout << '!' << endl;
  cout << k << endl;
  for (int i = 0; i < n; i++) cout << a1[i] << " ";
  fflush(stdout);
}
