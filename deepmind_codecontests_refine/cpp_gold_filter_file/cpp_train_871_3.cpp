#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline string tostr(const T &x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
const double EPS = 1e-6;
const int INF = 1000 * 1000 * 1000;
const char CINF = 102;
const long long LINF = INF * 1ll * INF;
const double PI = 3.1415926535897932384626433832795;
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
unsigned int gcd(unsigned int a, unsigned int b) {
  return a ? gcd(b % a, a) : b;
}
struct grandi {
  map<int, int> mem;
  int doit(int k, int m) {
    if (mem.count(m)) return mem[m];
    int &res = mem[m];
    bool was[35] = {false};
    for (int i = 0; i < (k); ++i) {
      if (!(m & (1 << i))) continue;
      int mm = m;
      for (int a = 1; (i + 1) * a <= k; ++a) {
        mm &= ~(1 << ((i + 1) * a - 1));
      }
      was[doit(k, mm)] = true;
    }
    while (was[res]) ++res;
    return res;
  }
};
bool pw[1000000];
void precalc() {
  cout << "{";
  for (int k = 1; k <= 29; ++k) {
    cout << grandi().doit(k, (1 << k) - 1) << "," << endl;
  }
  cout << "}" << endl;
}
const int gr[] = {1, 2, 1, 4, 3, 2, 1, 5, 6,  2, 1, 8, 7,  5, 9,
                  8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
int main() {
  long long n;
  cin >> n;
  map<int, int> chains;
  long long s = 0;
  for (long long a = 2; a * a <= n; ++a) {
    if (pw[a]) continue;
    long long t = a;
    int k = 1;
    while (true) {
      t *= a;
      if (t > n) break;
      ++k;
      if (t < 800000) pw[t] = true;
    }
    if (k < 2) exit(123);
    ++chains[k];
    s += k;
  }
  chains[1] = n - s;
  int g = 0;
  for (map<int, int>::iterator it = chains.begin(); it != chains.end(); ++it) {
    int k = it->first;
    int c = it->second;
    if (c % 2 == 0) continue;
    g ^= gr[k - 1];
  }
  cout << (g ? "Vasya" : "Petya");
  return 0;
}
