#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  int x1, y1, z1;
  int a1, a2, a3, a4, a5, a6;
  int soma = 0;
  cin >> x >> y >> z;
  cin >> x1 >> y1 >> z1;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  if (x < 0) soma += a1;
  if (x > x1) soma += a2;
  if (y < 0) soma += a5;
  if (y > y1) soma += a6;
  if (z < 0) soma += a3;
  if (z > z1) soma += a4;
  cout << soma << endl;
  return 0;
}
