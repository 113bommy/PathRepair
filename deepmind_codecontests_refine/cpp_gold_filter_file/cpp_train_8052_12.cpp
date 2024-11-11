#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x;
  cin >> x;
  int a = x;
  int b = 7 - x;
  for (int i = 0; i < n; i++) {
    int c, d;
    cin >> c >> d;
    if (c == a || c == b || d == a || d == b) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
