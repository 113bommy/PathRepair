#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long power[N];
map<long long, int> f;
long long m, x, ans = 0;
vector<long long> ord_divs;
inline void add(long long &a, long long b, long long mod) {
  a += b;
  if (a >= mod) a -= mod;
}
long long mult(long long a, long long b, long long mod) {
  long long r = 0;
  while (b) {
    if (b & 1) add(r, a, mod);
    add(a, a, mod), b >>= 1;
  }
  return r;
}
long long bigMod(long long a, long long e, long long mod) {
  long long r = 1;
  while (e) {
    if (e & 1) r = mult(r, a, mod);
    a = mult(a, a, mod), e >>= 1;
  }
  return r;
}
void backtrack(int at, vector<pair<long long, int> > fac, long long cur_m,
               long long cur_phi) {
  if (at == fac.size()) {
    long long cur_ord = cur_phi;
    for (int i = 0; i < ord_divs.size(); ++i) {
      if (power[i] % cur_m == 1) {
        cur_ord = ord_divs[i];
        break;
      }
    }
    ans += cur_phi / cur_ord;
    return;
  }
  long long pr = fac[at].first;
  int expo = fac[at].second;
  for (int i = expo; i >= 0; --i) {
    backtrack(at + 1, fac, cur_m, cur_phi);
    cur_m /= pr, --fac[at].second;
    if (i > 1)
      cur_phi /= pr;
    else
      cur_phi /= (pr - 1);
  }
}
int main() {
  cin >> m >> x;
  long long _m = m;
  for (long long i = 2; i * i <= _m; ++i) {
    while (_m % i == 0) {
      ++f[i], _m /= i;
    }
  }
  if (_m > 1) {
    ++f[_m];
  }
  long long phi = m;
  for (auto it : f) {
    phi /= it.first;
    phi *= (it.first - 1);
  }
  vector<long long> divs;
  for (long long i = 1; i * i <= phi; ++i) {
    if (phi % i == 0) {
      divs.push_back(i);
      divs.push_back(phi / i);
    }
  }
  sort(divs.begin(), divs.end());
  long long ord = phi;
  for (long long d : divs) {
    if (bigMod(x, d, m) == 1) {
      ord = d;
      break;
    }
  }
  for (long long d : divs) {
    if (ord % d == 0) {
      power[ord_divs.size()] = bigMod(x, d, m);
      ord_divs.push_back(d);
    }
  }
  vector<pair<long long, int> > fac;
  for (auto it : f) {
    fac.push_back(pair<long long, int>(it.first, it.second));
  }
  backtrack(0, fac, m, phi);
  printf("%lld\n", ans);
  return 0;
}
