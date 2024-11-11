#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int l, r;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s >> l >> r;
    if (l >= 2400 && l < r) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
