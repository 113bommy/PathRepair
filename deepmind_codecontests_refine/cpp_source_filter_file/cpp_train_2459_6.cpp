#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const int MAXN = 500001;
pair<ll, ll> q[MAXN];
int qb = 0, qe = 0;
ll mdq;
void ad(ll val, ll last) {
  val -= mdq;
  last -= mdq;
  while ((qe > qb) && q[qe - 1].first <= val) qe--;
  q[qe++] = {val, last};
}
ll f[MAXN];
ll s[MAXN];
int a[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(20);
  memset(q, 0, sizeof(q));
  memset(f, 0, sizeof(f));
  int n, c;
  cin >> n >> c;
  s[0] = 0;
  for (int i = 1; i <= 2 * n - 1; i++) {
    cin >> a[i];
  }
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    mdq += (a[2 * i - 2] + a[2 * i - 1]);
    ad(f[i - 1] + a[2 * i - 1], a[2 * i - 1]);
    while (q[qb].second + mdq > c) {
      ll df = q[qb].second + mdq - c;
      q[qb].second -= df;
      q[qb].first -= df;
      if (qb + 1 == qe || q[qb + 1].first < q[qb].first) {
        break;
      }
      qb++;
    }
    f[i] = q[qb].first + mdq;
  }
  cout << f[n] << "\n";
}
