#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int porcentaje = ((n * y) + 99) / 100;
  cout << max(0, porcentaje - x) << '\n';
}
