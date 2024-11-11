#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, O = 1, E = 2;
  cin >> n >> a >> b;
  if (n > a * b) return cout << -1, 0;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if ((i + j) % 2 == 0 && O <= n)
        cout << O << ' ', O += 2;
      else if (E <= n)
        cout << E << ' ', E += 2;
      else
        cout << 0 << ' ';
    }
    cout << endl;
  }
}
