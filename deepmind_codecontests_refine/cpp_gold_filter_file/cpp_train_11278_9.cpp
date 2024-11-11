#include <bits/stdc++.h>
using namespace std;
int P[100010];
int main() {
  memset(P, 0, sizeof P);
  int a, b, m, r;
  cin >> a >> b >> m >> r;
  for (int i = 1; i <= m + 1; i++) {
    r = (a * r + b) % m;
    if (P[r]) {
      cout << i - P[r] << endl;
      break;
    } else {
      P[r] = i;
    }
  }
}
