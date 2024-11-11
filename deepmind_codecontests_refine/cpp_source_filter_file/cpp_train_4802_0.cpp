#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const long long maxn = (long long)1e5 + 100;
const long long maxm = (long long)52;
const int LOGN = 22;
const long long INF = 1e13;
const long long MOD = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-12;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  while (cin >> n) {
    vector<long long> a(n);
    for (int i = 1; i < n; i += 2) cin >> a[i];
    bool ok = true;
    long long sum = 0;
    long long last = 0;
    for (int i = 1; i < n; i += 2) {
      long long x = a[i];
      bool find = false;
      long long start = sqrt(x) + 2;
      long long my1 = INF;
      long long my2 = INF;
      for (int d = start; d >= 1; --d)
        if (x % d == 0) {
          long long s = x / d;
          if ((s + d) % 2 == 1) continue;
          long long y2 = (s + d) / 2;
          long long y1 = y2 - d;
          if (y1 < last) continue;
          if (y2 < my2) {
            my1 = y1;
            my2 = y2;
          }
        }
      if (my2 == INF) {
        ok = false;
        break;
      }
      a[i - 1] = my1 * my1 - sum;
      sum = my2 * my2;
      last = my2;
    }
    if (ok) {
      cout << "Yes\n";
      for (auto x : a) {
        cout << x << " ";
      }
      cout << endl;
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
