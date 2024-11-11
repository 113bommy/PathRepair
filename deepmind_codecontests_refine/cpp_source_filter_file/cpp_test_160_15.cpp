#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m, stx, sty, edx, edy;
int hang(int n, int stx, int edx) {
  if (stx == edx)
    return 0;
  else if (edx > stx)
    return (edx - stx);
  else
    return (n - stx) + (n - edx);
}
int lie(int m, int sty, int edy) {
  if (sty == edy)
    return 0;
  else if (edy > sty)
    return edy - sty;
  else
    return (m - sty) + (m - edy);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> stx >> sty >> edx >> edy;
    int res = n + 1;
    res = min(res, lie(m, sty, edy));
    res = min(res, hang(n, stx, edx));
    cout << res << '\n';
  }
  return 0;
}
