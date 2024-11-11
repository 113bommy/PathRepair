#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int res = 0, c;
  while (c = getchar(), c < '0' || c > '9')
    ;
  do {
    res = res * 10 + (c ^ 48);
  } while (c = getchar(), c >= '0' && c <= '9');
  return res;
}
pair<pair<int, int>, int> S[500010];
int ask[500010];
set<int> Set;
int main() {
  int N = read(), X = 0, Y = 0;
  for (int i = 1; i <= N; i++) {
    int a = getchar(), b = read(), c = read();
    if (b > c) swap(b, c);
    if (a == '+') {
      X = max(b, X);
      Y = max(c, Y);
    } else {
      printf(b >= X && c >= Y ? "YES" : "NO");
    }
  }
}
