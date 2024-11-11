#include <bits/stdc++.h>
using namespace std;
const long long Mod = 998244353;
const long long inf = 1e9;
long long fac[310], inv[310];
long long ni(int x) { return fac[x - 1] * inv[x] % Mod; }
struct yxg {
  long long k;
  vector<long long> v;
  long long ask(long long x) {
    x %= Mod;
    long long res = 0, p = 1;
    for (int i = 0; i < v.size(); i++) {
      res = (res + p * v[i] % Mod) % Mod;
      p = p * x % Mod;
    }
    return res;
  }
  yxg operator-(const yxg &a) const {
    yxg res;
    res.k = max(k, a.k);
    res.v.resize(max(v.size(), a.v.size()));
    for (int i = 0; i < v.size(); i++) {
      res.v[i] = v[i];
    }
    for (int i = 0; i < a.v.size(); i++) {
      res.v[i] = (res.v[i] - a.v[i] + Mod) % Mod;
    }
    return res;
  }
  yxg operator*(const long long &x) const {
    yxg res;
    res.k = k;
    for (int i = 0; i < v.size(); i++) {
      res.v.push_back(v[i] * x % Mod);
    }
    return res;
  }
  yxg shift(long long x) {
    yxg res;
    res.k = k + x;
    int n = v.size();
    long long w = (Mod - x) % Mod;
    for (int i = 0; i < n; i++) {
      long long now = 0, p = 1;
      for (int j = 0; i + j < n; j++) {
        now =
            (now + p * inv[j] % Mod * v[i + j] % Mod * fac[i + j] % Mod) % Mod;
        p = p * w % Mod;
      }
      now = now * inv[i] % Mod;
      res.v.push_back(now);
    }
    return res;
  }
  yxg cal(long long x) {
    yxg res;
    res.k = k;
    res.v.push_back(0);
    for (int i = 0; i < v.size(); i++) {
      res.v.push_back(ni(i + 1) * v[i] % Mod);
    }
    res.v[0] = (x - res.ask(k) + Mod) % Mod;
    return res;
  }
};
struct func {
  vector<yxg> v;
  long long ask(long long x) {
    for (int i = (int)(v.size()) - 1; i >= 0; i--) {
      if (v[i].k <= x) {
        return v[i].ask(x);
      }
    }
  }
  func operator-(const func &a) const {
    func res;
    int i = 0, j = 0;
    do {
      if (res.v.size() > 0 && res.v.back().k == max(v[i].k, a.v[j].k)) {
        res.v.pop_back();
      }
      res.v.push_back(v[i] - a.v[j]);
      if (i + 1 < v.size() &&
          (j + 1 == (int)a.v.size() || v[i + 1].k <= a.v[j + 1].k)) {
        i++;
      } else {
        j++;
      }
    } while (j + 1 <= a.v.size());
    return res;
  }
  func operator*(const long long &x) const {
    func res;
    for (int i = 0; i < v.size(); i++) {
      res.v.push_back(v[i] * x);
    }
    return res;
  }
  func shift(long long x) {
    func res;
    for (int i = 0; i < v.size(); i++) {
      res.v.push_back(v[i].shift(x));
    }
    return res;
  }
  func cal() {
    func res;
    long long now = 0;
    for (int i = 0; i < v.size(); i++) {
      if (i) {
        now = res.v[i - 1].ask(v[i].k);
      }
      res.v.push_back(v[i].cal(now));
    }
    return res;
  }
  void cut(long long x) {
    long long now = ask(x);
    for (int i = v.size() - 1; i >= 0; i--) {
      if (v[i].k >= x) {
        v.pop_back();
      } else {
        break;
      }
    }
    yxg tmp;
    tmp.k = x;
    tmp.v.push_back(now);
    v.push_back(tmp);
  }
  void print() {
    cerr << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
      cerr << v[i].k << " ";
      for (int j = 0; j < v[i].v.size(); j++) {
        cerr << v[i].v[j] << " ";
      }
      cerr << endl;
    }
    cerr << endl;
  }
};
long long pw(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % Mod;
    }
    y >>= 1;
    x = x * x % Mod;
  }
  return res;
}
int n;
int main() {
  fac[0] = 1;
  for (int i = 1; i <= 300; i++) {
    fac[i] = fac[i - 1] * i % Mod;
  }
  inv[300] = pw(fac[300], Mod - 2);
  for (int i = 299; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1) % Mod;
  }
  scanf("%d", &n);
  func res;
  yxg tmp;
  tmp.k = -inf;
  tmp.v.push_back(0);
  res.v.push_back(tmp);
  tmp.k = 0;
  tmp.v[0] = 1;
  res.v.push_back(tmp);
  long long p = pw(1000000, Mod - 2);
  for (int i = 0; i < n; i++) {
    long long l, r;
    l = 0;
    r = 1000000;
    res = res.cal();
    res = (res.shift(l) - res.shift(r)) * p;
    double x;
    cin >> x;
    res.cut(x * 1000000);
  }
  printf("%lld\n", res.ask(inf));
  return 0;
}
