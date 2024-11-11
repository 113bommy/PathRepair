#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] > s[i + 1]) {
      a = i;
      b = i + 1;
      break;
    }
  }
  if (a == 0 && b == 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << a << " " << b << endl;
  }
  return 0;
}
