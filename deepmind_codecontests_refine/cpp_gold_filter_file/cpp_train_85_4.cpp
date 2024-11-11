#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1000000000;

int main() {
  int n,m;cin>>n>>m;
  ll an[n],bn[n], cn[m],dn[m];
  rep(i,n) cin>>an[i]>>bn[i];
  rep(j,m) cin>>cn[j]>>dn[j];
  ll d, dmin, dx;
  rep(i,n) {
    dmin=INF;
    rep(j,m) {
      d = abs(cn[j]-an[i]) + abs(dn[j]-bn[i]);
      if (d < dmin) {
        dmin = d;
        dx = j+1;
      }
    }
    cout << dx << endl;
  }
}
