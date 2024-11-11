#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1LL << 62;
inline double ttime(double t) {
  double tt = ((double)t) / CLOCKS_PER_SEC;
  return tt;
}
void boost() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  boost();
  long long int n;
  cin >> n;
  long long int st[n][2];
  long long int x, y;
  for (long long int i = 0; i < (n); i++) cin >> st[i][0] >> st[i][1];
  long long int res = st[0][0];
  for (long long int i = (1); i <= (n - 1); i++) {
    long long int k = st[i][0];
    while (k <= res) {
      k += (st[i][1]);
    }
    res = k;
  }
  cout << res << "\n";
  return 0;
}
