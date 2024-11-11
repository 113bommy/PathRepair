#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, t, a, b, da, db;
  cin >> x >> t >> a >> b >> da >> db;
  for (int i = 0; i <= t; i++)
    for (int h = 0; h <= 1; h++)
      for (int j = 0; j <= t; j++)
        for (int s = 0; s <= 1; s++)
          if (((a - (da * i)) * h) + ((b - (db * j)) * s) == x) {
            cout << "YES" << endl;
            return 0;
          }
  cout << "NO" << endl;
  return 0;
}
