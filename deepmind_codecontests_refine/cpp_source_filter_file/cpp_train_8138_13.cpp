#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, vector<T> a) {
  os << "( ";
  for (T &first : a) os << first << " ";
  os << ")" << endl;
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> a) {
  os << "( ";
  for (T first : a) os << first << " ";
  os << ")" << endl;
  return os;
}
template <typename X, typename Y>
ostream &operator<<(ostream &os, pair<X, Y> a) {
  os << "(" << a.first << " " << a.second << ") ";
  os.flush();
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, complex<T> a) {
  os << "(r=" << a.real() << " i=" << a.imag() << ") ";
  os.flush();
  return os;
}
template <typename X, typename Y>
pair<X, Y> &operator-=(pair<X, Y> &A, pair<X, Y> B) {
  A.first -= B.first;
  A.second -= B.second;
  return A;
}
template <typename X, typename Y>
pair<X, Y> &operator+=(pair<X, Y> &A, pair<X, Y> B) {
  A.first += B.first;
  A.second += B.second;
  return A;
}
template <typename X, typename Y>
X operator*(pair<X, Y> A, pair<X, Y> B) {
  return A.first * B.first + A.second * B.second;
}
template <typename X, typename Y>
X operator^(pair<X, Y> A, pair<X, Y> B) {
  return A.first * B.second - A.second * B.first;
}
template <typename X, typename Y>
X operator^(X a, Y b) {
  return a ^= b;
}
template <typename X, typename Y>
X operator+(X a, Y b) {
  return a += b;
}
template <typename X, typename Y>
X operator-(X a, Y b) {
  return a -= b;
}
template <typename X, typename Y>
X operator*(X a, Y b) {
  return a *= b;
}
template <typename X, typename Y>
X operator/(X a, Y b) {
  return a /= b;
}
const int base = 1000000007;
long long power(long long a, long long n, long long mod = base) {
  a = a < 0 ? (mod - (-a) % mod) : (a % mod);
  long long r = 1;
  while (n) {
    if (n & 1) r = r * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return r;
}
void solve(int);
int32_t main(int32_t argc, char **argv) {
  if (argc > 2) {
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 1; i <= t; ++i) solve(i);
  if (0)
    cout << "Time"
         << " = " << (((long long)(clock() * 1000 / CLOCKS_PER_SEC))) << endl;
  return 0;
}
void solve(int testID) {
  int n, m;
  auto pos = [&n](int k, int first) {
    if (first > k) return first;
    if (first == k) return 0;
    return first + 1;
  };
  cin >> n >> m;
  vector<int> first(m);
  for (auto &e : first) {
    cin >> e;
    --e;
  }
  {
    int n = 0;
    for (int i = 1; i < m; ++i)
      if (first[i] != first[n]) {
        first[++n] = first[i];
      }
    first.resize(m = n + 1);
  }
  vector<vector<int> > lst(n);
  for (int i = 0; i < m; ++i) {
    lst[first[i]].push_back(i);
  }
  auto f = [&](int k) {
    long long ans = 0;
    for (int i = 1; i < m; ++i) {
      ans += abs(pos(k, first[i]) - pos(k, first[i - 1]));
    }
    return ans;
  };
  long long ans;
  for (int k = 0; k < n; ++k) {
    if (k == 0) {
      ans = f(k);
      cout << ans << " ";
      continue;
    }
    for (int sign : {-1, 1}) {
      int t = sign == -1 ? k - 1 : k;
      unordered_set<int> S;
      for (int change : {k - 1, k})
        for (int i : lst[change]) {
          if (i) S.insert(i);
          if (i + 1 < n) S.insert(i + 1);
        }
      for (int i : S)
        ans += sign * abs(pos(t, first[i]) - pos(t, first[i - 1]));
    }
    cout << ans << " ";
    if (0)
      cout << "ans"
           << " = " << (ans) << endl;
    if (0)
      cout << "f(k)"
           << " = " << (f(k)) << endl;
  }
}
