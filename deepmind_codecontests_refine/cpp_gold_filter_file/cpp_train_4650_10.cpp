#include <bits/stdc++.h>
using namespace std;
long long i, j, q;
long long n, m, p, k, t, s, h, f;
long long a, b, c, d;
long long x, y, z, l, r;
long long one = 1, zero = 0, ans = 0;
long long mod = 1000000007;
long long INF = 1000000000000000000;
long long a1, a2, a3, a4, a5, a6, a7;
string st1, st2, st3;
char ch1, ch2, ch3;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  ifstream fin("Text.txt");
  cin >> n >> a1 >> a2;
  vector<long long> vca(n), vcb(n), vc(n);
  for (i = 0; i < n; i++) cin >> vca[i];
  for (i = 0; i < n; i++) cin >> vcb[i];
  for (i = 0; i < n; i++) {
    if (vca[i] > vcb[i]) swap(vca[i], vcb[i]);
  }
  a1 += a2;
  for (i = 0; i < n; i++) vc[i] = vcb[i] - vca[i];
  a7 = a1;
  for (i = 0; i < a1; i++) {
    a3 = 0;
    for (j = 0; j < n; j++) {
      if (vc[j] > vc[a3]) a3 = j;
    }
    if (vc[a3]) {
      vc[a3]--;
      a7--;
    }
  }
  for (i = 0; i < n; i++) ans += vc[i] * vc[i];
  ans += (a7 & 1);
  cout << ans << endl;
  return 0;
}
