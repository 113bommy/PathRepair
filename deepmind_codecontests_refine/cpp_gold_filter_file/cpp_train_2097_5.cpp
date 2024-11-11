#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  os << "[ ";
  for (auto e : v) os << e << " ";
  return os << "]";
}
template <typename T, typename V>
ostream& operator<<(ostream& os, set<T, V> v) {
  os << "{ ";
  for (auto e : v) os << e << " ";
  return os << "}";
}
template <typename T, typename V, typename S>
ostream& operator<<(ostream& os, map<T, V, S> v) {
  os << "{ ";
  for (auto e : v) os << e << " ";
  return os << "}";
}
template <typename T, typename V>
ostream& operator<<(ostream& os, pair<T, V> x) {
  return os << "( " << x.first << ", " << x.second << " )";
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& e : v) is >> e;
  return is;
}
template <typename T, typename V>
istream& operator>>(istream& is, pair<T, V>& x) {
  return is >> x.first >> x.second;
}
template <typename T>
T divfloor(T a, T b) {
  assert(b != 0);
  if (a >= 0 && b > 0 || a <= 0 && b < 0) return a / b;
  return (a % b == 0) ? a / b : a / b - 1;
}
template <typename T>
T divceil(T a, T b) {
  assert(b != 0);
  if (a >= 0 && b > 0 || a <= 0 && b < 0)
    return (a % b == 0) ? a / b : a / b + 1;
  return a / b;
}
void solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
using mat = vector<vector<ll>>;
const ll MOD = 1e9 + 7;
mat ID(int n) {
  auto a = mat(n, vector<ll>(n, 0));
  for (int i = 0; i < n; ++i) a[i][i] = 1;
  return a;
}
mat matmult(mat A, mat B) {
  int n = A.size();
  mat C(A.size(), vector<ll>(A.size()));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        C[i][j] += A[i][k] * B[k][j] % MOD;
        C[i][j] %= MOD;
      }
    }
  }
  return C;
}
mat matpow(mat A, ll e) {
  int n = A.size();
  if (e == 0) {
    return ID(n);
  }
  mat h = matpow(A, e / 2);
  h = matmult(h, h);
  if (e % 2 == 0) {
    return h;
  }
  return matmult(A, h);
}
void solve() {
  ll n;
  int m;
  cin >> n >> m;
  vector<vector<ll>> A(2 * m, vector<ll>(m, 0));
  for (int i = 0; i < m; ++i) {
    A[i][i] = 1;
  }
  for (int i = m; i < 2 * m; ++i) {
    for (int j = 0; j < m; ++j) {
      A[i][j] = A[i - 1][j] + A[i - m][j];
    }
  }
  auto B = vector<vector<ll>>(m, vector<ll>(m));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      B[i][j] = A[i + m][j];
    }
  }
  B = matpow(B, n / m);
  auto row = B[n % m];
  ll ans = 0;
  for (int i = 0; i < m; ++i) {
    ans = (ans + row[i]) % MOD;
  }
  cout << ans << "\n";
}
