#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      m[c]++;
    }
    for (int i = 1; i <= 200; i++) {
      if (!m[i]) x--;
      if (x == -1) {
        cout << i - 1 << endl;
        break;
      }
    }
  }
}
