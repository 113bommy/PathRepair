#include <bits/stdc++.h>
using namespace std;
struct _ {
  _() { ios_base::sync_with_stdio(0); }
} _;
template <class A, class B>
ostream &operator<<(ostream &o, pair<A, B> t) {
  o << "(" << t.first << ", " << t.second << ")";
  return o;
}
template <class T>
string tostring(T first, int len = 0, char c = '0') {
  stringstream ss;
  ss << first;
  string r = ss.str();
  if (r.length() < len) r = string(len - r.length(), c) + r;
  return r;
}
template <class T>
void PV(T a, T b, int n = 0, int w = 0, string s = " ") {
  int c = 0;
  while (a != b) {
    cout << tostring(*a++, w, ' ');
    if (a != b && (n == 0 || ++c % n))
      cout << s;
    else
      cout << "\n";
    cout.flush();
  }
}
template <class T>
inline bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
const long long linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 111111;
long long f(long long first) {
  vector<int> d;
  while (first > 0) {
    d.push_back(first % 2);
    first /= 2;
  }
  reverse((d).begin(), (d).end());
  long long res = 0;
  int n = d.size();
  for (int i = 0; i < n; i++) {
    for (int j = (i == 0); j < d[i]; j++) {
      vector<int> v(d.begin(), d.begin() + i);
      v.push_back(j);
      long long f[64] = {};
      for (int T = 1; T < n; T++) {
        if (n % T) continue;
        if (T <= v.size()) {
          int ok = 1;
          for (int k = T; k < v.size(); k++)
            if (v[k] != v[k - T]) {
              ok = 0;
              break;
            }
          for (int t = 2; t < T && ok; t++)
            if (T % t == 0) {
              int can = 1;
              for (int k = t; t < v.size(); t++)
                if (v[k] != v[k - t]) {
                  can = 0;
                  break;
                }
              if (can) ok = 0;
            }
          if (ok) f[T]++;
        } else {
          f[T] = 1LL << (T - v.size());
          for (int t = 2; t < T; t++)
            if (T % t == 0) {
              int can = 1;
              for (int k = t; t < v.size(); t++)
                if (v[k] != v[k - t]) {
                  can = 0;
                  break;
                }
              if (can) f[T] -= f[t];
            }
        }
        res += f[T];
      }
    }
  }
  for (int i = 1; i < n; i++) {
    long long f[64] = {};
    for (int j = 1; j < i; j++) {
      if (i % j == 0) {
        f[j] += (1LL << (j - 1));
        for (int k = 1; k < j; k++)
          if (j % k == 0) f[j] -= f[k];
      }
      res += f[j];
    }
  }
  return res;
}
int main() {
  long long l, r;
  cin >> l >> r;
  long long res = f(r + 1) - f(l);
  cout << res << endl;
  return 0;
}
