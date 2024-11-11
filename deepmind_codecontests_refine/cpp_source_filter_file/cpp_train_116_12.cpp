#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int a;
  cin >> a >> s;
  for (int k = 0; k < a - 1; k++) {
    if (s[k] < s[k + 1]) {
      cout << "YES" << endl << k + 1 << " " << k + 2;
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
