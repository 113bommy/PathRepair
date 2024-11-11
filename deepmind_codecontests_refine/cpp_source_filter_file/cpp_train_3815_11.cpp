#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
using pii = pair<long long, long long>;
void xmax(long long& a, long long b) { a = max(a, b); }
void xmin(long long& a, long long b) { a = min(a, b); }
void print(vc<long long>& a, string second) {
  cerr << "prinitng " << second << "\n";
  for (long long i = 0; i < a.size(); i++) {
    cerr << a[i] << " ";
  }
  cerr << endl;
}
const long long mod = 1e9 + 9;
vc<long long> par;
long long fi(long long a) {
  if (par[a] == a) return a;
  return par[a] = fi(par[a]);
}
long long uni(long long a, long long b) {
  fi(a);
  fi(b);
  if (par[a] == par[b]) return false;
  par[a] = par[b];
  return true;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  par = vc<long long>(n);
  for (long long i = 0; i < n; i++) {
    par[i] = i;
  }
  long long anz = 1;
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    if (!uni(a, b)) anz = (anz * 2) % mod;
    cout << (mod + anz - 1) % mod << "\n";
  }
}
