#include <bits/stdc++.h>
using namespace std;
int query(int x, int y) {
  cout << "? " << x << " " << y << "\n";
  cout.flush();
  int a;
  cin >> a;
  return a;
}
int main() {
  int a = 0, b = 0, c = query(0, 0);
  for (int i = 29; i >= 0; i--) {
    int A = query(a ^ (1 << i), b), B = query(a, b ^ (1 << i));
    if (A == B) {
      if (c == 1)
        a ^= (1 << i);
      else
        b ^= (1 << i);
      c = A;
    } else if (A == -1) {
      a ^= (1 << i);
      b ^= (1 << i);
    }
  }
  cout << "! " << a << " " << b << "\n";
  cout.flush();
  return 0;
}
