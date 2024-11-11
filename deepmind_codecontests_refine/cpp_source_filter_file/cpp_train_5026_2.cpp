#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    if (a[0] + a[1] + a[2] + a[3] == 1) {
      for (int i = 0; i < 4; i++) cout << (a[i] == 1 ? "Ya" : "Tidak") << " ";
      cout << endl;
    } else {
      int k = 1;
      for (int i = 0; i < 2; i++) {
        k *= pow(-1, a[i]);
      }
      if (k == 1) {
        cout << "Tidak Tidak ";
        cout << (a[1] + a[2] == 0 ? "Tidak " : "Ya ");
        cout << (a[3] + a[0] == 0 ? "Tidak" : "Ya");
      } else {
        cout << (a[1] + a[2] == 0 ? "Tidak " : "Ya ");
        cout << (a[3] + a[0] == 0 ? "Tidak " : "Ya ");
        cout << "Tidak Tidak ";
      }
      cout << endl;
    }
  }
  return 0;
}
