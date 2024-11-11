#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3c3c3c3c;
const long long LINF = 1ll * INF * INF * 2;
const int N = 200001;
const int MOD = 1000000007;
int rev(int x) {
  if (x == 1) return 1;
  x = x % MOD;
  if (x < 0) x += MOD;
  return ((int)(1ll * (((int)(1ll * ((MOD - 1)) * ((MOD / x)) % MOD))) *
                (rev(MOD % x)) % MOD));
}
int n, k, rk;
int _p[N];
int _sp[N];
int _rp[N];
int phi[N];
int mp[N];
void make() {
  rk = rev(k);
  _p[0] = 1, _rp[0] = 1;
  _sp[0] = 1;
  for (int i = 1; i <= n; i++) _p[i] = ((int)(1ll * (_p[i - 1]) * (k) % MOD));
  for (int i = 1; i <= n; i++) _sp[i] = (_sp[i - 1] + _p[i]) % MOD;
  for (int i = 1; i <= n; i++)
    _rp[i] = ((int)(1ll * (_rp[i - 1]) * (rk) % MOD));
  for (int i = 2; i * i < N; i++) {
    if (mp[i]) continue;
    for (int j = i; j < N; j += i) {
      if (!mp[j]) mp[j] = i;
    }
  }
  for (int i = 2; i < N; i++)
    if (!mp[i]) mp[i] = i;
  phi[1] = 1;
  for (int i = 2; i < N; i++) {
    int t = i / mp[i];
    if (t % mp[i])
      phi[i] = ((int)(1ll * (phi[i / mp[i]]) * (mp[i] - 1) % MOD));
    else
      phi[i] = ((int)(1ll * (phi[i / mp[i]]) * (mp[i]) % MOD));
  }
}
int pow(int x) {
  if (x >= 0)
    return _p[x];
  else
    return _rp[-x];
}
int sum(int x) { return _sp[x] - _sp[0]; }
void findD(int x, vector<int> &v) {
  v.clear();
  v.push_back(1);
  while (x > 1) {
    int p = mp[x], cnt = 0;
    while (!(x % p)) x /= p, cnt++;
    int s = ((int)((v).size()));
    for (int i = 0; i < s; i++) {
      int cur = v[i];
      for (int j = 0; j < cnt; j++) {
        cur = ((int)(1ll * (cur) * (p) % MOD));
        v.push_back(cur);
      }
    }
  }
  sort((v).begin(), (v).end());
}
void count(int l, int r, vector<int> &v, vector<int> &c) {
  c.resize(((int)((v).size())));
  for (int i = 0; i < ((int)((v).size())); i++) {
    int d = v[i];
    c[i] = r / d - (l - 1) / d;
  }
  for (int i = ((int)((v).size())) - 1; i >= 0; i--) {
    for (int j = i + 1; j < ((int)((v).size())); j++) {
      if (!(v[j] % v[i])) c[i] -= c[j];
    }
  }
}
int main(void) {
  scanf("%d%d", &n, &k);
  make();
  long long ans = sum(n - 1);
  for (int xy = 2; xy <= n; xy++) {
    vector<int> v;
    findD(xy, v);
    long long temp = 0;
    for (int d : v) temp += 1ll * phi[xy / d] / 2 * 2 * pow(d);
    ans += temp % MOD;
  }
  for (int k = 1; k < n; k++) {
    vector<int> v, c;
    findD(n + k, v);
    count(k + 1, n - 1, v, c);
    long long temp = 0;
    for (int i = 0; i < ((int)((v).size())); i++) {
      int d = v[i];
      int cnt = c[i];
      if (d > k)
        temp += 1ll * pow(d) * cnt;
      else
        temp += 1ll * pow(k) * cnt;
    }
    if (!((n + k) % 2)) temp -= 1ll * pow((n + k) / 2);
    ans += temp % MOD;
  }
  ans % MOD;
  ans = ((int)(1ll * (ans) * (pow(-n)) % MOD));
  cout << ans;
}
