#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  string in;
  int x, y;
  cin >> in;
  x = in[0] - 'a' + 1;
  y = in[1] - '0';
  if ((x == 1 && y == 1) || (x == 8 && y == 8) || (x == 1 && y == 8) ||
      (x == 8 && y == 1))
    cout << 3;
  else if (x == 1 || x == 8 || y == 1 || y == 8)
    cout << 5;
  else
    cout << 8;
}
