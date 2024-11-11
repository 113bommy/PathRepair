#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int a[10000], b[10000];
  for (int n = 0; n < N; n++) {
    cout << "? " << 0 << " " << n << endl;
    cin >> a[n];
  }
  for (int n = 0; n < N; n++) {
    cout << "? " << n << " " << 0 << endl;
    cin >> b[n];
  }
  int nm = 0, fa = 0;
  int ac[10000], bc[10000];
  for (int n = 0; n < N; n++) {
    for (int x = 0; x < N; x++) {
      ac[x] = a[x] ^ n;
    }
    for (int x = 0; x < N; x++) {
      bc[x] = b[x] ^ ac[0];
    }
    bool p = true;
    for (int x = 0; x < N; x++) {
      if (ac[bc[x]] != x) {
        p = false;
      }
    }
    if (p) {
      fa = n;
      nm++;
    }
  }
  cout << "!" << endl;
  cout << nm << endl;
  fa = fa ^ a[0];
  for (int x = 0; x < N; x++) {
    if (x) cout << " ";
    cout << (fa ^ b[x]);
  }
  cout << endl;
  return 0;
}
