#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[6] = {4, 8, 15, 16, 23, 42};
  int qr[4];
  for (int i = 0; i < 4; i++) {
    cout << "? " << i + 1 << " " << i + 2 << endl;
    cin >> qr[i];
  }
  do {
    bool ok = 1;
    for (int i = 0; i < 4; i++) {
      ok &= (a[i] * a[i + 1] == qr[i]);
      if (!ok) break;
    }
    if (ok) break;
  } while (next_permutation(a, a + 6));
  cout << "! ";
  for (int x : a) cout << x << " ";
  cout << endl;
  return 0;
}
