#include <bits/stdc++.h>
using namespace std;
string tostring(int number) {
  stringstream ss;
  ss << number;
  return ss.str();
}
int main() {
  ios::sync_with_stdio(false);
  string res;
  int x, y;
  cin >> x >> y;
  if (y == 0 && x != 1)
    cout << "No solution";
  else {
    cout << y;
    for (int i = 0; i < x - 1; i++) cout << 0;
  }
  cout << endl;
}
