#include <bits/stdc++.h>
using namespace std;
long long bkr, ykr, yball, gball, bball, y, b, l;
int main() {
  cin >> ykr >> bkr >> yball >> gball >> bball;
  y = 2 * yball + gball;
  b = gball + 3 * bball;
  if (yball > ykr) l = l + y + ykr;
  if (bball > bkr) l = l + b - bkr;
  cout << l;
}
