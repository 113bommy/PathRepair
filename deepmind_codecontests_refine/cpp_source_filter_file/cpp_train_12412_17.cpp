#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long INF = 1e18;
const double eps = 1e-10;
mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
template <class T>
inline void upmin(T &x, T y) {
  x = x > y ? y : x;
}
template <class T>
inline void upmax(T &x, T y) {
  x = x < y ? y : x;
}
template <class A, class B>
string to_string(pair<A, B> p);
template <class A, class B, class C>
string to_string(tuple<A, B, C> p);
template <class A, class B, class C, class D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <class A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <class A, class B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class A, class B, class C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <class A, class B, class C, class D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug() { cerr << endl; }
template <class T, class... U>
void debug(const T &h, const U &...t) {
  cerr << to_string(h) << ' ';
  debug(t...);
}
const int maxn = 4e5 + 233;
int sg[5000][3];
int n, x, y, z, T;
long long a[maxn];
int period;
int mex(vector<int> t) {
  bool f[10] = {};
  for (auto &i : t) f[i] = 1;
  int res = 0;
  while (f[res]) res++;
  return res;
}
bool check(int b, int c) {
  for (int i = 0; i < 3; i++)
    if (sg[c][i] != sg[b][i]) return false;
  return true;
}
long long getsg(long long b, int c) {
  if (b < 0) b = 0;
  if (b <= 2000) return sg[b][c];
  b -= (b - period) / period * period;
  return sg[b][c];
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
  cin >> T;
  while (T--) {
    cin >> n >> x >> y >> z;
    period = 0;
    for (int i = 1; i <= 2000; i++) {
      sg[i][0] = mex(vector<int>{sg[max(i - x, 0)][0], sg[max(i - y, 0)][1],
                                 sg[max(i - z, 0)][2]});
      sg[i][1] = mex(vector<int>{sg[max(i - x, 0)][0], sg[max(i - z, 0)][2]});
      sg[i][2] = mex(vector<int>{sg[max(i - x, 0)][0], sg[max(i - y, 0)][1]});
    }
    for (int i = 1; i <= 50; i++) {
      bool f = true;
      for (int j = 50; i + j <= 2000; j++) {
        f &= check(j, j + i);
      }
      if (f) {
        period = i;
        break;
      }
    }
    assert(period);
    long long sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum ^= getsg(a[i], 0);
    int res = 0;
    for (int i = 1; i <= n; i++) {
      long long tmp = sum ^ getsg(a[i], 0);
      if (tmp == getsg(a[i] - x, 0)) res++;
      if (tmp == getsg(a[i] - y, 1)) res++;
      if (tmp == getsg(a[i] - z, 2)) res++;
    }
    cout << res << '\n';
  }
  return 0;
}
