#include <bits/stdc++.h>
using namespace std;
bool reb[100][100];
int n;
int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= max(a, b); i++) {
    if (i % 2 == 1)
      a = a - i;
    else
      b = b - i;
    if (a < 0) {
      cout << "Vladik\n";
      break;
    } else if (b < 0) {
      cout << "Valera\n";
      break;
    }
  }
}
