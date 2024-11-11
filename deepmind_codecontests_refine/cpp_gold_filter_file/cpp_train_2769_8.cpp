#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  int s, f;
  s = f = 1;
  while (s < min(A, B)) {
    f *= ++s;
  }
  cout << f;
  return 0;
}
