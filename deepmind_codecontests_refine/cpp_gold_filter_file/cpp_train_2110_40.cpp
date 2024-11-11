#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << n << endl;
      continue;
    }
    for (int i = 1; i < n; i++) {
      cout << i + 1 << " ";
    }
    cout << 1 << endl;
  }
}
