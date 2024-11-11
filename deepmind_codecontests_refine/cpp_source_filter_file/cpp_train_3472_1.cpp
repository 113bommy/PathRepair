#include <bits/stdc++.h>
using namespace std;
int x, y, z, temp, Maxx, Maxy, Min = 10000, a, b;
long double r2;
long long tempo;
int main() {
  cin >> x;
  for (int i = 0; i < x; ++i) {
    cin >> temp;
    if (temp > Maxx) Maxx = temp;
  }
  cin >> y;
  for (int i = 0; i < y; ++i) {
    cin >> temp;
    if (temp > Maxy) Maxy = temp;
  }
  cin >> z;
  for (int i = 0; i < z; ++i) {
    cin >> temp;
    if (temp < Min && temp != 0) Min = temp;
  }
  cin >> a >> b;
  tempo = b * Maxy * Maxx * Maxx;
  r2 = sqrt((long double)tempo / (long double)(a * Min + b * Maxy));
  cout << setprecision(12) << r2;
  return 0;
}
