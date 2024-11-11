#include <bits/stdc++.h>
using namespace std;
template <class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& p) {
  return o << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& vc) {
  o << "{";
  for (const T& v : vc) o << v << ",";
  o << "}";
  return o;
}
using ll = long long;
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int N;
  cin >> N;
  V<int> b(N);
  for (int i = 0; i < (int)(N); i++) cin >> b[i];
  {
    bool allsame = true;
    for (int i = 0; i < (int)(N); i++)
      if (b[0] != b[i]) allsame = false;
    if (allsame) {
      if (b[0] == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < (int)(N); i++) cout << 1 << " ";
        cout << endl;
      } else {
        cout << "NO" << endl;
      }
      return 0;
    }
  }
  int shift = -1;
  for (int i = 0; i < (int)(N); i++)
    if (b[i] < b[(i + 1) % N]) {
      shift = (N + N - 2 - i) % N;
      V<int> c(N);
      for (int i = 0; i < (int)(N); i++) c[(i + shift) % N] = b[i];
      b = c;
      break;
    }
  ll X = 0;
  for (int i = 0; i < (int)(N - 1); i++) X += b[i];
  X += TEN(12) * b[N - 1];
  V<ll> a(N);
  a[0] = X;
  for (int i = 1; i <= (int)(N - 2); i++) a[i] = a[i - 1] - b[i - 1];
  a[N - 1] = b[N - 1];
  true;
  true;
  for (int i = 0; i < (int)(N); i++) {
    assert(a[i] % a[(i + 1) % N] == b[i]);
  }
  cout << "YES" << endl;
  for (int i = 0; i < (int)(N); i++) cout << a[(i + shift) % N] << " ";
}
