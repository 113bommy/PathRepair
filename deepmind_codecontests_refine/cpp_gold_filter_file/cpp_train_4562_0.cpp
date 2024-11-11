#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);

  int n, q; cin >> n >> q;
  vector<ll> a(n);
  for(int i=0;i<n;++i) {
    cin >> a[i];
  }
  reverse(a.begin(), a.end());

  vector<ll> sum(n+1), evensum(n+1);
  for(int i=0;i<n;++i) {
    sum[i+1] = sum[i] + a[i];
    evensum[i+1] = evensum[i] + (i % 2 == 0 ? a[i] : 0);
  }

  vector<ll> ths, vals;
  for(int i=0;i<(n-1)/2;++i) {
    ll th = (a[i+1] + a[i*2+2])/2 + 1;
    ll val = (sum[i+1] - sum[0]) + (evensum[n] - evensum[i*2+2]);
    ths.push_back(th);
    vals.push_back(val);
  }

  reverse(ths.begin(), ths.end());
  reverse(vals.begin(), vals.end());
  for(int i=0;i<q;++i) {
    ll x; cin >> x;
    int it = upper_bound(ths.begin(), ths.end(), x) - ths.begin();
    if(it == 0) cout << sum[(n+1)/2] - sum[0] << endl;
    else cout << vals[it-1] << endl;
  }
}
