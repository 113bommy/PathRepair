#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int a = 0, b = 0;
  for (int i = 0; i < n - 11; ++i) {
    if (s[i] == '8') {
      ++a;
    } else {
      ++b;
    }
  }
  if (a >= b) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
