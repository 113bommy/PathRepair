#include <bits/stdc++.h>
using namespace std;
template <class T>
void Debug(T x) {
  cerr << "Debug: "
       << "--[" << x << ']' << "--\n";
}
const int INF = 0x3f3f3f3f, m197 = (int)1e9 + 7;
void s_solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b;
  for (auto &x : a) {
    cin >> x;
  }
  b = a;
  sort(b.begin(), b.end());
  sort(a.begin(), a.end(), greater<int>());
  long long s = 0;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    s += a[i];
    if (s == 0) ok = false;
  }
  if (!ok) {
    ok = true;
    s = 0;
    for (int i = 0; i < n; ++i) {
      s += b[i];
      if (s == 0) ok = false;
    }
    if (ok) a = b;
  }
  cout << (ok ? "YES" : "NO") << '\n';
  if (ok) {
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int _T = 1, _C = 1;
  cin >> _T;
  while (_C++ <= _T) {
    s_solve();
  }
  return 0;
}
