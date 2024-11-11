#include <bits/stdc++.h>
using namespace std;
set<int> t[1000];
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 3; i < 1000; ++i) {
    if (360 % i != 0) continue;
    int mid = 360 / i;
    for (int j = 0; j < i - 2; j++) {
      t[i].insert((j + 1) * mid);
    }
  }
  int q, n;
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 0; i < 1000; ++i) {
      if (t[i].find(n * 2) != t[i].end()) {
        cout << i << endl;
        break;
      }
    }
  }
}
