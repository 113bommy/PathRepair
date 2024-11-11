#include <bits/stdc++.h>
using namespace std;
int main() {
  int h1, a1, d1, cost = 1 << 30;
  int h2, a2, d2;
  int hc, ac, dc;
  cin >> h1 >> a1 >> d1 >> h2 >> a2 >> d2 >> hc >> ac >> dc;
  for (int i = 0; i <= 800; i++) {
    for (int j = 0; j <= 500; j++)
      for (int k = 0; k <= 500; k++) {
        int h_curr = h1 + i;
        int a_curr = a1 + j;
        int d_curr = d1 + k;
        int hm_curr = h2;
        if (max(0, a_curr - d2) == 0 && max(0, a2 - d_curr) == 0) continue;
        while (hm_curr > 0 && h_curr >= 0) {
          hm_curr -= max(0, a_curr - d2);
          h_curr -= max(0, a2 - d_curr);
        }
        if (h_curr > 0 && hm_curr <= 0)
          cost = min(cost, i * hc + j * ac + k * dc);
      }
  }
  cout << cost;
}
