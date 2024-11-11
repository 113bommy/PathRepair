#include <bits/stdc++.h>
using namespace std;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vc<vc<T>>;
template <class T>
void mkuni(vector<T>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
long long rand_int(long long l, long long r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<long long>(l, r)(gen);
}
template <class T>
void print(T x, int suc = 1) {
  cout << x;
  if (suc == 1)
    cout << '\n';
  else
    cout << ' ';
}
template <class T>
void print(const vector<T>& v, int suc = 1) {
  for (int i = 0; i < v.size(); i++)
    print(v[i], i == (int)(v.size()) - 1 ? suc : 2);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b * c < a)
      print(-1);
    else {
      if (d > c)
        print(a);
      else {
        long long L = 1, R = 1e12, ans = -1;
        auto getv = [&](long long x) {
          long long damage = x * a;
          long long t = (x - 1) * d;
          long long cc = min(x - 1, c / d);
          long long heal = (x - cc - 1) * b * c;
          heal += (1 + cc) * cc / 2 * d * b;
          return damage - heal;
        };
        while (L <= R) {
          long long len = (R - L) / 3;
          long long lp = L + len, rp = R - len;
          long long lv = getv(lp), rv = getv(rp);
          if (lv >= rv) {
            ans = lv;
            R = rp - 1;
          } else {
            ans = rv;
            L = lp + 1;
          }
        }
        assert(ans != -1);
        print(ans);
      }
    }
  }
}
