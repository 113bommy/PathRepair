#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long int* iptr;
typedef char* cptr;
template <typename L, typename R>
istream& operator>>(istream& in, pair<L, R>& P) {
  in >> P.first >> P.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& V) {
  for (auto& elem : V) in >> elem;
  return in;
}
template <class L, class R>
ostream& operator<<(ostream& out, pair<L, R> const& val) {
  if (out.rdbuf() == cout.rdbuf())
    return (out << val.first << " " << val.second);
  else
    return (out << "{" << val.first << "," << val.second << "}");
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& X) {
  if (os.rdbuf() == cout.rdbuf()) {
    for (auto& y : X) os << y << " ";
    return os;
  } else {
    os << "[ ";
    for (auto& y : X) os << y << " ";
    return os << "]";
  }
}
template <typename T>
void d0(T t) {
  cout << t << " ";
}
template <typename T>
void dall(T t) {
  cout << t << "\n";
}
template <typename T, typename... Args>
void dall(T t, Args... args) {
  cout << t << " ";
  dall(args...);
}
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
const long long int mod = 1e9 + 7;
const long long int inf = 1e18;
const long long int MAXN = 1e6;
const long double eps = 1e-8;
long long int pwr(long long int base, long long int exp,
                  long long int m = mod) {
  long long int res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % m;
    base = (base * base) % m;
    exp /= 2;
  }
  return res % m;
}
long long int gcd(long long int A, long long int B) {
  if (B == 0) return A;
  return gcd(B, A % B);
}
long long int lcm(long long int A, long long int B) {
  return (A * B) / gcd(A, B);
}
int digits(long long int N, long long int base = 2) {
  if (N == 0)
    return 1;
  else if (base == 10)
    return floor(log10(N)) + 1;
  else
    return floor(log2(N)) + 1;
}
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int temp = n / 2;
  temp--;
  for (auto i = temp + 1; i < n; i++) {
    if (s[i] == '0') {
      dall(1, i + 1, 1, i);
      return;
    }
  }
  for (auto i = 0; i < n - temp - 1; i++) {
    if (s[i] == '0') {
      dall(i + 1, n, i + 2, n);
      return;
    }
  }
  dall(1, 2 * temp + 2, 1, temp + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(15);
  cerr << fixed << setprecision(5);
  long long int TEST_CASES = 1, CASE_NO = 1;
  cin >> TEST_CASES;
  while (TEST_CASES--) {
    42;
    solve();
    CASE_NO++;
    42;
  }
  return 0;
}
