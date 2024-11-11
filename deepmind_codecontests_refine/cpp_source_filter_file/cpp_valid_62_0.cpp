#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Os")
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int last_pos = 0;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      if (t == 0) last_pos = i;
    }
    last_pos++;
    for (int i = 0; i < last_pos; i++) {
      cout << i + 1 << ' ';
    }
    cout << n + 1 << ' ';
    for (int i = last_pos; i < n; i++) {
      cout << i + 1 << ' ';
    }
    cout << '\n';
  }
}
