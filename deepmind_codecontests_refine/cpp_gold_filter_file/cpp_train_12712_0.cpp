#include <bits/stdc++.h>
using namespace std;
int main() {
  int maxi = 0, som = 0, n;
  cin >> n;
  int t[n + 1];
  t[0] = 0;
  int pos_i, pos_f, max_pos;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    t[i] += t[i - 1];
  }
  for (pos_f = n; pos_f > 0; pos_f--) {
    for (pos_i = 0; pos_i + pos_f <= n; pos_i++) {
      if (t[pos_i + pos_f] - t[pos_i] > 100 * pos_f) {
        cout << pos_f << endl;
        return 0;
      }
    }
  }
  cout << "0" << endl;
}
