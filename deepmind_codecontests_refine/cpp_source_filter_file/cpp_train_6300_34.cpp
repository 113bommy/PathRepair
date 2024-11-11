#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C &a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C &a4, C b4) {
  a4 = max(a4, b4);
}
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
long double tra[101], p[101];
long double ileda(long long i) { return (1 - tra[i]) * p[i] / tra[i]; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> p[i];
    p[i] /= 100;
    tra[i] = p[i];
  }
  long double res = 0;
  long double ost = 0;
  for (long long i = n; i < 100000; i++) {
    long double ak = 1;
    for (long long i = 0; i < n; i++) ak *= tra[i];
    long double naj = -1;
    long long kt = 0;
    for (long long i = 0; i < n; i++) {
      long double pom = ileda(i);
      if (pom > naj) {
        naj = pom;
        kt = i;
      }
    }
    tra[kt] += (1 - tra[kt]) * p[kt];
    res += (ak - ost) * i;
    ost = ak;
  }
  cout << res << endl;
}
