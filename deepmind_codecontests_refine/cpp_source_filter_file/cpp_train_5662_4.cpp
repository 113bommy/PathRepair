#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  if (a.size() != b.size()) {
    cout << "NO";
    return 0;
  } else if (a == b) {
    cout << "YES";
    return 0;
  }
  int c1 = 0;
  int c2 = 0;
  for (int i = 0; i < a.size(); i++) {
    c1 += a[i] == '1';
    c2 += b[i] == '1';
  }
  if (c1 > 1 && c2 > 1) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
