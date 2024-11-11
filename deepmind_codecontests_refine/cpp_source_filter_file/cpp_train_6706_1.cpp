#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const int Inf = 1000000007;
const double Pi = acos(-1);
void Fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, q, sz = 0;
int a[100005], b[100005], c[100005];
set<int> P;
void Solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
    P.insert(i);
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int type;
    cin >> type;
    if (type == 2) {
      int x;
      cin >> x;
      cout << b[x] - a[x] << '\n';
    } else {
      sz = 0;
      int x, y;
      cin >> x >> y;
      set<int>::iterator it = P.lower_bound(x);
      for (it; it != P.end(); it++) {
        if (a[*it] > y) {
          a[*it] -= y;
          break;
        } else {
          y -= a[*it];
          a[*it] = 0;
          c[sz] = *it;
          sz++;
        }
      }
      for (int j = 0; j < sz; j++) {
        P.erase(c[j]);
      }
    }
  }
}
int main() {
  Fastio();
  Solve();
}
