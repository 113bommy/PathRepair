#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h, k, resultado = 0;
  cin >> w >> h >> k;
  while (k--) {
    resultado += ((w * 2) + (h * 2)) - 4;
    h -= 2;
    w -= 2;
  }
  cout << resultado << endl;
  return 0;
}
