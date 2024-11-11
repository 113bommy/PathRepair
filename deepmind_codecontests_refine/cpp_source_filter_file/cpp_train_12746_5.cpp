#include <bits/stdc++.h>
using namespace std;
int main() {
  string x, y = "AIOXHVWTYM";
  cin >> x;
  for (int i = 0; i < x.size(); i++) {
    if (y.find(x[i]) == -1) {
      cout << "NO";
      return 0;
    }
  }
  y.clear();
  y = x;
  reverse(y.begin(), y.end());
  if (y == x)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
