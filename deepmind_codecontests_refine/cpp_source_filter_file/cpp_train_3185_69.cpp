#include <bits/stdc++.h>
using namespace std;
int main() {
  int L, B, year = 0;
  cin >> L >> B;
  do {
    L *= 3;
    B *= 2;
    year += 1;
  } while (L < B);
  cout << year;
  return 0;
}
