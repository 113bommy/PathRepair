#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)2e9;
const long long inf = (long long)2e18;
const long double eps = (long double)1e-8;
const long long mod = (long long)998244353;
const long long MAXN = (long long)1e5 + 1;
const long long MAXC = (long long)1e6 + 1;
const long long MAXE = (long long)1000;
const long long MAXLOG = 21;
const long long maxlen = (long long)1e5;
const long long asci = (long long)256;
const long long block = 480;
const long double PI = acos(-1);
const long double e = 2.7182818284;
template <class T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (T &cnt : arr) {
    in >> cnt;
  }
  return in;
};
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  cin >> a;
  vector<long long> b(n);
  cin >> b;
  multiset<pair<long long, long long> > aa, bb;
  for (int i = 0; i < n; ++i) {
    aa.insert(make_pair(a[i], a[n - i - 1]));
    bb.insert(make_pair(b[i], b[n - i - 1]));
  }
  if (aa == bb)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(30);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
