#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &it : a) cin >> it;
    int cnt_0 = 0;
    int summ = 0;
    for (int it : a) {
      if (it == 0) {
        cnt_0++;
      }
      summ += it;
    }
    if (cnt_0 > 0) {
      if (summ + cnt_0 > 0) {
        cout << cnt_0 << "\n";
      } else {
        cout << cnt_0 + 1 << "\n";
      }
    } else if (summ == 0) {
      cout << 1 << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
  return 0;
}
