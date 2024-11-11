#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0, p = 0;
  string a, b;
  cin >> a >> b;
  if (a.length() != b.length())
    cout << "NO";
  else {
    for (int i = 0; i < a.length(); i++) {
      if (a[i] == 1) c = 1;
      if (b[i] == 1) p = 1;
    }
    if (c == 0 && p == 1)
      cout << "NO";
    else if (c == 1 && p == 0)
      cout << "NO";
    else
      cout << "YES";
  }
  return 0;
}
