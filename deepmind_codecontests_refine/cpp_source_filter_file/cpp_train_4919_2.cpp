#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  if (2 * n >= s) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < (n - 1) * 2; i++) {
      cout << 2 << " ";
    }
    cout << (s - 2) * (n - 1) << "\n";
    cout << 1 << "\n";
  }
  return 0;
}
