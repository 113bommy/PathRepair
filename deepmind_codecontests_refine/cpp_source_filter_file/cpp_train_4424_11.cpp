#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  cin >> x;
  for (int i = 0; i < x.length(); i++) {
    for (int j = 0; j < x.length() - i; j++) {
      string y = x;
      y.erase(i, j);
      if (y == "CODEFORCES") {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
