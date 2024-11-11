#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, l, r;
  cin >> t;
  while (t--) {
    map<int, int> mm;
    cin >> n;
    m = n;
    while (m--) {
      cin >> l;
      mm[l]++;
    }
    int sum = 0, noba = 0, ind = 1;
    for (int i = 0; i <= n; i++) {
      if (ind) {
        cout << sum + mm[i] << " ";
        if (mm[i] == 0) {
          while (mm[noba] == 1) {
            if (noba == 0) break;
            noba--;
          }
          if (mm[noba] <= 1)
            ind = 0;
          else {
            sum += i - noba;
            mm[i]++;
            mm[noba]--;
          }
        } else
          noba = i;
      } else
        cout << "-1  ";
    }
    cout << endl;
  }
  return 0;
}
