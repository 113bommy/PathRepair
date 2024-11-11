#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, tmp;
  int t;
  cin >> t;
  bool cek[51];
  while (t--) {
    cin >> n;
    memset(cek, false, sizeof(cek));
    for (int i = 0; i < 2 * n; i++) {
      cin >> tmp;
      if (cek[tmp] == false) {
        cout << tmp << " ";
        cek[tmp] = true;
      } else {
        continue;
      }
    }
    cout << endl;
  }
}
