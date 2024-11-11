#include <bits/stdc++.h>
using namespace std;
int main() {
  int pt, ans1 = 0, ans2 = 0;
  cin >> pt;
  int pos[pt];
  for (int i = 0; i < pt; i++) {
    cin >> pos[i];
  }
  for (int i = 0; i < pt; i++) {
    if (pos[i] > 500000) {
      if (ans2 < 1000000 - (pos[i])) ans2 = 1000000 - (pos[i]);
    } else if (pos[i] < 500000) {
      if (ans1 < pos[i] - 1) {
        ans1 = pos[i] - 1;
      }
    } else {
      cout << 500000 - 1 << endl;
      return 0;
    }
  }
  cout << max(ans1, ans2) << endl;
  return 0;
}
