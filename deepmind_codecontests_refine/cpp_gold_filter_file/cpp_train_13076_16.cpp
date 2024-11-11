#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans = 0;
  int cls[7] = {0, 0, 0, 0, 0, 0, 0};
  int n;
  cin >> n;
  char v[7];
  while (n--) {
    for (int c = 0; c < 7; ++c) {
      cin >> v[c];
      if (v[c] == '1') {
        cls[c]++;
        if (ans < cls[c]) {
          ans = cls[c];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
