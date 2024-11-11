#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, p, q, counter = 0;
  cin >> a;
  while (a--) {
    cin >> p >> q;
    if (p + 1 < q) counter++;
  }
  cout << counter;
}
