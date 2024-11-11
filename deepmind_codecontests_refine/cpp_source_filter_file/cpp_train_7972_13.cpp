#include <bits/stdc++.h>
#pragma comment(linker, "/stack:640000000")
using namespace std;
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = acos(-1.0);
template <class T>
inline T gcd(T a, T b) {
  return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template <class T>
inline T lcm(T a, T b) {
  return ((a) / gcd((a), (b)) * (b));
}
template <typename T>
string NumberToString(T Number) {
  ostringstream second;
  second << Number;
  return second.str();
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int t, n, m;
vector<long long> a, b, ind;
int main() {
  while (~scanf("%d", &n)) {
    a.clear();
    b.clear();
    ind.clear();
    int k = n / 2 + 1;
    long long asum = 0, bsum = 0;
    for (int i = 1; i <= (n); i++) {
      long long x;
      scanf("%lld", &x);
      a.push_back(x);
      ind.push_back(i - 1);
      asum += x;
    }
    for (int i = 1; i <= (n); i++) {
      long long x;
      scanf("%lld", &x);
      b.push_back(x);
      bsum += x;
    }
    for (int j = 1; j <= (100); j++) {
      long long anow = 0, bnow = 0;
      for (int i = 0; i < (k); i++) {
        int id = ind[i];
        anow += a[id];
        bnow += b[id];
      }
      if (anow * 2 > asum && bnow * 2 > bsum) break;
      random_shuffle(ind.begin(), ind.end());
    }
    printf("%d\n", k);
    for (int i = 0; i < (k); i++) {
      if (i) printf(" ");
      printf("%lld", ind[i] + 1);
    }
    puts("");
  }
  return 0;
}
