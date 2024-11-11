#include <bits/stdc++.h>
using namespace std;
const int MaxN = 50 + 17;
const int INF = 1e9 + 17;
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  if (n > m) swap(n, m);
  if (n == 1) {
    if (n == 1 && m == 1) cout << 0, exit(0);
    if (m % 3 == 0) cout << m - m / 3, exit(0);
    m += 3;
    cout << (m - 3) - m / 3, exit(0);
  }
  if (n == 2) {
    if (m == 2) cout << 2, exit(0);
    if (m == 3) cout << 4, exit(0);
    if (m == 4) cout << 5, exit(0);
    cout << m * 2 - (m + 2) / 2, exit(0);
  }
  if (n == 3) {
    int Ans = n * m - (m - m / 5);
    if (m == 9) ++Ans;
    if (m == 13) ++Ans;
    cout << Ans, exit(0);
  }
  if (n == 4) {
    int Ans = 0;
    if (m % 4 == 3 || m % 4 == 0)
      Ans = (n * m) - m;
    else
      Ans = (n * m) - m - 1;
    if (m == 10)
      cout << 30, exit(0);
    else
      cout << Ans;
  }
  if (n == 5) {
    if (m == 5) cout << 18, exit(0);
    if (m == 6) cout << 22, exit(0);
    if (m == 7) cout << 26, exit(0);
    if (m == 8) cout << 28, exit(0);
  }
  if (n == 6) cout << 26, exit(0);
  return 0;
}
