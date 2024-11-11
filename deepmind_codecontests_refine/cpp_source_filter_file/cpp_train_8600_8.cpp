#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, a;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &a);
    if (a == 1 || a == 2 || a == 3 || a == 7 || a == 5 || a == 1) {
      cout << -1 << "\n";
    } else if (a % 2 == 0) {
      cout << a / 4 << "\n";
    } else {
      int f = a - 9;
      cout << f / 4 + 1 << "\n";
    }
  }
}
