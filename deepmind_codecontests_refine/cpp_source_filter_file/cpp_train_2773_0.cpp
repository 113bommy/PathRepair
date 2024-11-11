#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, h, m;
  cin >> x >> h >> m;
  int S = 0;
  while (m % 10 != 7 && h % 10 != 7) {
    m -= x;
    if (m < 0) {
      m = 60 - m;
      h--;
      if (h < 0) h = 23;
    }
    S++;
  }
  cout << S;
}
