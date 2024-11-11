#include <bits/stdc++.h>
using namespace std;
int main() {
  int c1, c2, c3, c4, c5;
  cin >> c1 >> c2 >> c3 >> c4 >> c5;
  if ((c1 + c2 + c3 + c4 + c5) % 5 == 0 && c1 + c2 + c3 + c4 + c5 != 0)
    cout << (c1 + c2 + c3 + c4 + c5) / 5;
  else
    cout << -1;
}
