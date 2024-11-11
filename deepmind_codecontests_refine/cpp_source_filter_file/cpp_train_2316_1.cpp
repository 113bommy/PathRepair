#include <bits/stdc++.h>
using namespace std;
inline void read(register int *n) {
  register char c;
  *n = 0;
  do {
    c = getchar();
  } while (c < '0' || c > '9');
  do {
    *n = c - '0' + *n * 10;
    c = getchar();
  } while (c >= '0' && c <= '9');
}
const int INF = 87654321;
int cnt(int a, int b) {
  if (a == 1 && b == 1) return 0;
  if (a == b) return INF;
  if (a > b) swap(a, b);
  return cnt(a, b - a) + 1;
}
int main() {
  int n;
  cin >> n;
  int mn = INF;
  for (register int i = (1); i < (int)(n); ++i) mn = min(mn, cnt(i, n));
  cout << mn << "\n";
  return 0;
}
