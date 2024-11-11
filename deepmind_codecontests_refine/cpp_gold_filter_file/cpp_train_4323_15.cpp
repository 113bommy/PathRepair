#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    for (int i = 25; i >= 0; --i) {
      if (n >> i & 1) cout << i + 1 << ' ';
    }
    cout << endl;
  }
  return 0;
}
