#include <bits/stdc++.h>
using namespace std;
string answer = "", s1;
enum Queru { Alica, Bob };
Queru Q1 = Alica;
long long evklid(long long a, long long b) {
  if (a % b == 0) {
    return a / b;
  } else {
    return evklid(b, a % b);
  }
}
inline long long go_evklid(long long a, long long b) {
  if (a < b) {
    swap(a, b);
  }
  return evklid(a, b);
}
int main() {
  long long x, y;
  cin >> x >> y;
  if (go_evklid(x, y) > 1) {
    cout << "Impossible" << endl;
    return 0;
  }
  while (x != 0 && y != 0) {
    if (y > x) {
      if (x == 1) --y;
      cout << y / x << 'B';
      y = (y % x);
    } else {
      if (y == 1) --x;
      cout << x / y << 'A';
      x = (x % y);
    }
  }
  return 0;
}
