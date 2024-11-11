#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int t = 1;
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      if (t > b) {
        cout << "0 ";
      } else {
        t = max(a + 1, t + 1);
        cout << t - 1 << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
