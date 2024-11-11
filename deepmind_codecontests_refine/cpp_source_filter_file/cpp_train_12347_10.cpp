#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const long long INF = 2e18;
int m[3], n[3], s[3], val[MAXN], pm[MAXN], c;
long long mypow(int p, int cnt) {
  if (cnt == 1) return p;
  long long ret = mypow(p, cnt / 2);
  long long ans = 1;
  if (cnt % 2) ans *= p;
  ans *= ret;
  ans *= ret;
  return ans;
}
vector<long long> V;
int b[22], ps[MAXN], cs[MAXN], cn[MAXN];
int main() {
  b[0] = 1;
  for (int i = 1; i < 22; i++) b[i] = b[i - 1] * 2;
  for (int i = 1; i < MAXN; i++) val[i] = i;
  for (int i = 2; i * i < MAXN; i++)
    if (val[i] == i)
      for (int j = i * i; j < MAXN; j += i) val[j] = i;
  for (int i = 2; i < MAXN; i++)
    if (val[i] == i) pm[c++] = i, ps[i] = c - 1;
  int ncase;
  for (scanf("%d", &ncase); ncase--;) {
    long long nn = 1;
    for (int i = 0; i < 3; i++) scanf("%d", n + i), nn *= n[i];
    long long mm = 1;
    for (int i = 0; i < 3; i++) scanf("%d", m + i), mm *= m[i];
    for (int i = 0; i < 3; i++) scanf("%d", s + i);
    for (int i = 0; i < c; i++) cn[i] = cs[i] = 0;
    cs[0]++;
    for (int i = 0; i < 3; i++) {
      int t = n[i];
      while (t != 1) {
        int p = val[t];
        while (t % p == 0) t /= p, cn[ps[p]]++;
      }
      t = s[i];
      while (t != 1) {
        int p = val[t];
        while (t % p == 0) t /= p, cs[ps[p]]++;
      }
    }
    V.clear();
    for (int i = 0; i < c; i++) {
      if (cn[i] > cs[i]) {
        V.push_back(mypow(pm[i], cs[i] + 1));
      }
    }
    long long ans = 0;
    for (int i = 0; i < b[V.size()]; i++) {
      int t = i, cnt = 0;
      long long tmp = 1;
      bool flg = false;
      for (int j = 0; j < V.size(); j++) {
        if (t % 2) {
          cnt++;
          if (INF / V[j] < tmp) {
            flg = true;
            break;
          }
          tmp *= V[j];
        }
        t /= 2;
      }
      if (flg) continue;
      if (cnt % 2)
        ans -= mm / tmp;
      else
        ans += mm / tmp;
    }
    V.clear();
    V.push_back(1);
    for (int i = 0; i < c; i++) {
      int tp = pm[i];
      int sz = V.size();
      for (int j = 1; j <= cs[i]; j++) {
        for (int k = 0; k < sz; k++)
          if (V[k] * tp <= nn) V.push_back(V[k] * tp);
        tp *= pm[i];
      }
    }
    for (int i = 0; i < V.size(); i++)
      if (nn >= V[i]) ans++;
    printf("%lld\n", ans);
  }
  return 0;
}
