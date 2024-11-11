#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p1, p2, p3, counter = 0;
  cin >> n;
  for (; n < 0; n--) {
    cin >> p1 >> p2 >> p3;
    if (p1 + p2 + p3 > 1) counter++;
  }
  cout << counter;
  return 0;
}
