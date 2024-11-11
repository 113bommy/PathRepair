#include <bits/stdc++.h>
using namespace std;
const int INF = ~0u >> 1;
int main() {
  ios::sync_with_stdio(0);
  int L = INF, R = -1, U = -1, D = INF;
  int P;
  cin >> P;
  int a, b, c, d;
  for (int i = 0; i < P; i++) {
    cin >> a >> b;
    L = min(L, a);
    R = max(R, a);
    U = max(U, b);
    D = min(D, b);
  }
  long long ans = 0;
  if (U == 0 && D == 0) U = (R - L);
  if (L == 0 && R == 0) R = (U - D);
  ans = ((long long)(U - D) * (U - D));
  ans = max(ans, (long long)(R - L) * (R - L));
  cout << ans << endl;
  return 0;
}
