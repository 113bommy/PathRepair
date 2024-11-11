#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    for (int i = 25; i >= 0; --i) {
      if (n >> i & 1) cout << (1 << i) << ' ';
    }
    cout << endl;
  }
  return 0;
}
