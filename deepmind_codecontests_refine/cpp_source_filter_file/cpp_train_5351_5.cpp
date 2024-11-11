#include <bits/stdc++.h>
using namespace std;
int x, y, d, c;
bool f;
string n[11];
int main() {
  cin >> x >> y;
  for (int i = 0; i < x; i++) cin >> n[i];
  for (int i = 0; i < x; i++) {
    f = false;
    for (int j = 0; j < y; j++)
      if (n[i][j] == 'S') f = true;
    if (!f) {
      d += y;
      c++;
    }
  }
  for (int i = 0; i < y; i++) {
    f = false;
    for (int j = 0; j < x; j++)
      if (n[i][j] == 'S') f = true;
    if (!f) {
      d += (x - c);
    }
  }
  cout << d;
  return 0;
}
