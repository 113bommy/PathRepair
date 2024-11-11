#include <bits/stdc++.h>
using namespace std;
int main() {
  int n1, n2, k1, k2, turn = 1;
  cin >> n1 >> n2 >> k1 >> k2;
  while (true) {
    n1 -= k1;
    if (n1 <= 0) {
      turn = 1;
      break;
    }
    n2 -= k2;
    if (n2 <= 0) {
      turn = 2;
      break;
    }
  }
  if (turn == 1)
    cout << "First";
  else
    cout << "Second";
  return 0;
}
