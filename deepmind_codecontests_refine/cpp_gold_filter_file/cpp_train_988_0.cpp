#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-10;
double zero(double d) { return d < EPS ? 0.0 : d; }
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '(' << p.first << ',' << p.second << ')';
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  os << '[';
  for (int i = 0; i < (int)(a.size()); i++) os << (i ? " " : "") << a[i];
  return os << ']';
}
string toString(int i) {
  stringstream ss;
  ss << i;
  return ss.str();
}
const int MOD = 1000000007;
long long fpow(long long a, long long k, int M) {
  long long res = 1ll;
  long long x = a;
  while (k != 0) {
    if ((k & 1) == 1) res = (res * x) % M;
    x = (x * x) % M;
    k >>= 1;
  }
  return res;
}
int main() {
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(8);
  ios_base::sync_with_stdio(false);
  int n, bx;
  cin >> n >> bx;
  vector<int> a(n);
  for (int i = 0; i < (int)(n); i++) cin >> a[i];
  int m, by;
  cin >> m >> by;
  vector<int> b(m);
  for (int i = 0; i < (int)(m); i++) cin >> b[i];
  long long ans1 = 0, ans2 = 0;
  for (int i = 0; i < (int)(n); i++) {
    ans1 = ans1 * bx + a[i];
  }
  for (int i = 0; i < (int)(m); i++) {
    ans2 = ans2 * by + b[i];
  }
  if (ans1 == ans2)
    cout << "=" << endl;
  else if (ans1 < ans2)
    cout << "<" << endl;
  else
    cout << ">" << endl;
  return 0;
}
