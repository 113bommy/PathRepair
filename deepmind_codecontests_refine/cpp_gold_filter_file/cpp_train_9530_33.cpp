#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  int a, b;
  for (int i = 1; i <= n; i++) {
    cin >> s >> a >> b;
    if (a >= 2400 && b > a) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
