#include <bits/stdc++.h>
using namespace std;
int main() {
  char x, y;
  cin >> x >> y;
  cout << (x < y ? "<" : (y == x ? "==" : ">")) << endl;
}
