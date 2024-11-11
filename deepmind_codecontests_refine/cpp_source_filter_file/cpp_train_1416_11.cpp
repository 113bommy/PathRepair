#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  char a;
  cin >> x >> a >> y;
  if (x == 12) x = 0;
  cout << (x * 30) + (y / 2) << " " << y * 6;
}
