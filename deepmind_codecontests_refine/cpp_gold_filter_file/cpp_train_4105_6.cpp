#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, h, m = 1;
  cin >> a;
  int b[a];
  for (int g = 0; g < a; g++) {
    cin >> b[g];
  }
  h = b[0];
  for (int c = 0; c < a; c++) {
    if (h < b[c]) {
      h = b[c];
      m = c + 1;
    }
  }
  sort(b, b + a);
  h = b[a - 2];
  cout << m << " " << h;
  return 0;
}
