#include <bits/stdc++.h>
using namespace std;
string x, y;
string buff = "";
int main(int argc, char const *argv[]) {
  cin >> x;
  cin >> y;
  for (int i = 0; i < x.length(); i++) {
    if (y[i] > x[i]) {
      cout << -1 << endl;
      return 0;
    }
    if (x[i] == y[i]) {
      buff += (x[i] + 1);
    } else {
      buff += y[i];
    }
  }
  cout << buff << endl;
  return 0;
}
