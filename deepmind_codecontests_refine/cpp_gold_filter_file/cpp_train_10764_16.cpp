#include <bits/stdc++.h>
using namespace std;
bitset<1234> bits[1234];
struct circ {
  unsigned long long r;
  long long x;
  long long y;
};
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  long long kn[n][2];
  circ ci[m];
  for (int i = 0; i < n; i++) cin >> kn[i][0] >> kn[i][1];
  for (int i = 0; i < m; i++) cin >> ci[i].r >> ci[i].x >> ci[i].y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((kn[i][0] - ci[j].x) * (kn[i][0] - ci[j].x) +
              (kn[i][1] - ci[j].y) * (kn[i][1] - ci[j].y) <
          ci[j].r * ci[j].r)
        bits[i][j] = 1;
    }
  }
  int a, b;
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    a--;
    b--;
    cout << (bits[a] ^ bits[b]).count() << endl;
  }
  return 0;
}
