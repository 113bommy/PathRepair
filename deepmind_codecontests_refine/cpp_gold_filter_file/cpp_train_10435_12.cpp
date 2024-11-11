#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<ii>;
const ll MOD = 998244353;
const int INF = 1e9 + 9;
using cn = complex<double>;
const double PI = acos(-1);
const int CC = 30;
const int MAXN = 1 << 18;
void fft(cn pol[], int n, bool invert) {
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) {
      j ^= bit;
    }
    j ^= bit;
    if (i < j) swap(pol[i], pol[j]);
  }
  cn root[n];
  root[0] = 1;
  if (!invert)
    root[1] = cn(cos(2 * PI / n), sin(2 * PI / n));
  else
    root[1] = cn(cos(-2 * PI / n), sin(-2 * PI / n));
  for (int i = 2; i < n; i++) {
    if (i % 2)
      root[i] = root[1] * root[i / 2] * root[i / 2];
    else
      root[i] = root[i / 2] * root[i / 2];
  }
  for (int len = 2; len <= n; len <<= 1) {
    for (int i = 0; i < n; i += len) {
      for (int j = 0; j < len / 2; j++) {
        cn even = pol[i + j], odd = pol[i + j + len / 2] * root[n / len * j];
        pol[i + j] = even + odd;
        pol[i + j + len / 2] = even - odd;
      }
    }
  }
  if (invert) {
    for (int i = 0; i < n; i++) {
      pol[i] /= n;
    }
  }
}
int n, m, p[CC];
string ss;
cn pola[MAXN], polb[MAXN];
int t[MAXN], s[MAXN];
ll t0[MAXN];
double t1[MAXN], t2[MAXN], t3[MAXN];
void multiply(double t[]) {
  fft(pola, MAXN, false);
  fft(polb, MAXN, false);
  for (int i = 0; i < MAXN; ++i) {
    pola[i] *= polb[i];
  }
  fft(pola, MAXN, true);
  for (int i = 0; i < n; ++i) {
    t[i] = pola[i].real();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 1; i <= 26; ++i) cin >> p[i];
  cin >> ss;
  reverse(ss.begin(), ss.end());
  m = ss.size();
  for (int i = 0; i < m; ++i) s[i] = ss[i] - 'a' + 1;
  cin >> ss;
  n = ss.size();
  for (int i = 0; i < n; ++i) t[i] = ss[i] - 'a' + 1;
  for (int i = 0; i < MAXN; ++i) pola[i] = t[i] * t[i] * t[i];
  for (int i = 0; i < MAXN; ++i) polb[i] = s[i] + p[s[i]];
  multiply(t1);
  for (int i = 0; i < MAXN; ++i) pola[i] = t[i] * t[i];
  for (int i = 0; i < MAXN; ++i)
    polb[i] = s[i] * s[i] + 4 * s[i] * p[s[i]] + p[s[i]] * p[s[i]];
  multiply(t2);
  for (int i = 0; i < MAXN; ++i) pola[i] = t[i];
  for (int i = 0; i < MAXN; ++i) polb[i] = s[i] * p[s[i]] * (s[i] + p[s[i]]);
  multiply(t3);
  for (int i = 0; i < n; ++i) {
    t0[i + 1] = t0[i] + t[i] * t[i] * t[i] * t[i];
  }
  ll t5 = 0;
  for (int i = 0; i < m; ++i) {
    t5 += s[i] * s[i] * p[s[i]] * p[s[i]];
  }
  for (int i = m - 1; i < n; ++i) {
    cout << (abs(t0[i + 1] - t0[i - m + 1] - 2 * t1[i] + t2[i] - 2 * t3[i] +
                 t5) < 0.9);
  }
  cout << "\n";
}
