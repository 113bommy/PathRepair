#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, d, n, m, k;
  scanf("%d%d%d%d%d", &c, &d, &n, &m, &k);
  int tmp = m * n - k, tmp2;
  int minim = tmp * d;
  for (int i = 0; i <= tmp; i++) {
    tmp2 = (ceil)((double)(tmp - i) / (double)n);
    if (minim > (tmp2 * c + i * d)) {
      minim = tmp2 * c + i * d;
    }
  }
  cout << minim << endl;
}
