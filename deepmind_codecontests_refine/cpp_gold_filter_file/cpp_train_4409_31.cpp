#include <bits/stdc++.h>
using namespace std;
struct Halum {
  long long x, y;
};
void DenTofieM() {
  long long n, m, k = 0, X1, Y1;
  scanf("%lld %lld", &n, &m);
  char ar[n][m];
  Halum br[3];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> ar[i][j];
      if (ar[i][j] == '*') {
        br[k].x = i + 1;
        br[k].y = j + 1;
        k++;
      }
    }
  }
  if (br[0].x == br[1].x) {
    X1 = br[2].x;
    if (br[0].y == br[2].y) {
      Y1 = br[1].y;
    } else if (br[1].y == br[2].y) {
      Y1 = br[0].y;
    }
  } else {
    X1 = br[0].x;
    if (br[0].y == br[1].y) {
      Y1 = br[2].y;
    } else if (br[0].y == br[2].y) {
      Y1 = br[1].y;
    }
  }
  cout << X1 << " " << Y1 << "\n";
}
int main() {
  DenTofieM();
  return 0;
}
