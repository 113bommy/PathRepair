#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const long long LLINF = (long long)1e18;
const int LOG = 17;
const int N = (int)2e5 + 5;
const double PI = 3.141592653589793;
const double eps = 0.000005;
void operator delete(void* a) {}
void operator delete[](void* a) {}
int n, k, a, b, q;
int queries[N];
int pref[N], suff[N];
void add_pref(int x, int delta) {
  for (; x < N; x |= x + 1) {
    pref[x] += delta;
  }
}
void add_suff(int x, int delta) {
  x = N - x;
  for (; x < N; x |= x + 1) {
    suff[x] += delta;
  }
}
int get_pref(int x) {
  int ret = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    ret += pref[x];
  }
  return ret;
}
int get_suff(int x) {
  int ret = 0;
  x = N - x;
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    ret += suff[x];
  }
  return ret;
}
int main() {
  cin >> n >> k >> a >> b >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int d, x;
      cin >> d >> x;
      add_pref(d, -min(b, queries[d]));
      add_suff(d, -min(a, queries[d]));
      queries[d] += x;
      add_pref(d, min(b, queries[d]));
      add_suff(d, min(a, queries[d]));
    } else {
      int p;
      cin >> p;
      cout << get_pref(p - 1) + get_suff(p + k);
    }
  }
  return 0;
}
