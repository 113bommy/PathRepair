#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int main() {
  int n;
  cin >> n;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    int p;
    string s;
    cin >> p;
    cin >> s;
    if (x == 0 and y == 0 and s != "South") {
      cout << "NO" << endl;
      return 0;
    }
    if (x == 0 and y == -20000 and s != "North") {
      cout << "NO" << endl;
      return 0;
    }
    if (s == "North")
      y += p;
    else if (s == "South")
      y -= p;
    else if (s == "East")
      x += p;
    else
      x -= p;
    if (y < -20000 and y > 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (y == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
