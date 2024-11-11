#include <bits/stdc++.h>
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double EPS = 0.001;
const long double EPS2 = 1e-6;
const long double PI = acos(-1);
const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int a228 = 18;
const int inf = 1e9;
const long long kekmod = 1791791791;
const long long bestmod = 1148822869;
const long long INF = 4e18;
const int mod = 998244353;
int ss = 0;
int resq(int x) {
  for (int i = sqrt(x) - 1;; ++i)
    if (i * i >= x) return i;
}
const int MACSOS = 30000000;
bitset<MACSOS> kekos;
const int MAXN = 5e6 + 1;
int lp[MAXN];
int pr[MAXN / 10];
int keks = 0;
int divas[100000];
int kekosa = 0;
int cntos[100];
int primes[100];
void rec(int pos, int now) {
  if (pos == keks) {
    divas[kekosa++] = now;
    return;
  }
  for (int j = 0; j <= cntos[pos]; ++j) {
    rec(pos + 1, now);
    now *= primes[pos];
  }
}
int ya = 0;
int pers[100];
signed main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  srand(time(NULL));
  int n, m;
  cin >> n >> m;
  set<int> s;
  long long ans = 0;
  for (int i = 2; i < MAXN; ++i) {
    if (!lp[i]) {
      lp[i] = i;
      pr[ss++] = i;
    }
    for (int j = 0; j < ss && pr[j] * i < MAXN && pr[j] <= lp[i]; ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
  for (int c = 1; c <= m; ++c) {
    int loll = 0;
    int tc = c;
    ya = 0;
    while (tc > 1) {
      pers[ya++] = (lp[tc]);
      tc /= lp[tc];
    }
    int cnt = 1;
    keks = kekosa = 0;
    for (int i = 1; i < ya; ++i) {
      if (pers[i] != pers[i - 1]) {
        cntos[keks] = (cnt);
        cnt = 1;
        primes[keks++] = (pers[i - 1]);
      } else
        ++cnt;
    }
    if (c > 1) {
      cntos[keks] = cnt;
      primes[keks++] = (pers[ya - 1]);
    }
    rec(0, 1);
    sort(divas, divas + kekosa);
    for (int aj = 0; aj < kekosa; ++aj) {
      if (1ll * divas[aj] * divas[aj] > c) break;
      int j = divas[aj];
      int lol = c / j;
      if ((lol + j) % 2 == 0) {
        int b = (lol + j) / 2;
        if (b > n || b * b < c) continue;
        int a = max(lol, j) - min(lol, j);
        ++loll;
        a /= 2;
        kekos.set(-b + a + MACSOS / 3);
        kekos.set(-b - a + MACSOS / 3);
      }
    }
    int akek = resq(c);
    int obv = n - akek + 1;
    if (obv - loll < 0) continue;
    ans += (obv - loll) * 2;
  }
  cout << ans + kekos.count();
}
