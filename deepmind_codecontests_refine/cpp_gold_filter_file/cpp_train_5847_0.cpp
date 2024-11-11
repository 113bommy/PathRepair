#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream myFile("task.in");
  if (!myFile.fail()) {
    assert(freopen("task.in", "r", stdin));
  }
  int n, r = 0, b = 0;
  cin >> n;
  string str;
  cin >> str;
  for (int i = 0; i < n; i++) {
    if (str[i] == '(') {
      if (r <= b) {
        cout << "1";
        r++;
      } else {
        cout << "0";
        b++;
      }
    } else if (str[i] == ')') {
      if (r > b) {
        cout << "1";
        r--;
      } else {
        cout << "0";
        b--;
      }
    }
  }
  cout << endl;
  return 0;
}
