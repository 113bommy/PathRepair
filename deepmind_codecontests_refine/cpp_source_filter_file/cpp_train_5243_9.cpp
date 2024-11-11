#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int p[] = {2,       3,       5,       7,        13,       17,      19,
           31,      61,      89,      107,      127,      521,     607,
           1279,    2203,    2281,    3217,     4253,     4423,    9689,
           9941,    11213,   19937,   21701,    23209,    44497,   86243,
           110503,  132049,  216091,  756839,   859433,   1257787, 1398269,
           2976221, 3021337, 6972593, 13446917, 20996011, 24036583};
const long long int mod = 1000000007;
long long int mpow(int k) {
  long long int res = 1, a = 2;
  while (k) {
    if (k & 1) res = res * a % mod;
    a = a * a % mod;
    k >>= 1;
  }
  return res;
}
int n;
int main() {
  cin >> n;
  --n;
  long long int res = (mpow(p[n] - 1) + mod - 1) % mod;
  cout << res << endl;
  return 0;
}
