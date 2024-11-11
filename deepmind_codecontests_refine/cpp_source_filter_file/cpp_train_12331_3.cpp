#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const long long INF64 = (long long)1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
template <class T1>
void deb(T1 e) {
  cout << "-->" << e << "\n";
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << "-->" << e1 << " " << e2 << "\n";
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << "-->" << e1 << " " << e2 << " " << e3 << "\n";
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << "-->" << e1 << " " << e2 << " " << e3 << " " << e4 << "\n";
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << "-->" << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5
       << "\n";
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << "-->" << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " "
       << e6 << "\n";
}
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
};
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T1>
void js(T1 arr) {
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << "\n";
}
template <class T1, class T2, class T3>
void js(T1 arr, T2 start, T3 end) {
  for (auto it = start; it != end; it++) {
    cout << *it << " ";
  }
  cout << "\n";
}
template <typename T>
inline T gcd(T a, T b) {
  T c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
long long lcm(int x, int y) { return x * 1LL * y / gcd(x, y); }
void read(vector<int> &v) {
  int N = (int)v.size();
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
}
void fill(vector<int> &v, int N) {
  for (int i = 0; i < N; i++) {
    v[i] = 0;
  }
}
void Answer() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int n;
  cin >> n;
  int tota, totb;
  tota = a + b + c;
  totb = d + e + f;
  tota = ceil((1.0 * tota) / 5);
  ;
  totb = ceil((1.0 * tota) / 10);
  ;
  cout << (tota + totb <= n ? "YES" : "NO");
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    Answer();
  }
  return 0;
}
