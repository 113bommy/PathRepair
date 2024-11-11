#include <bits/stdc++.h>
using namespace std;
const int N = 31111;
long long BDD = 3e9;
vector<long long> p;
vector<int> st, ed;
vector<long long> base;
int nb;
int F(char c) {
  if (c == '?') return -1;
  if (isdigit(c)) return c - '0';
  return c - 'A' + 10;
}
int n;
long long a[N];
int nq = 0;
struct Q {
  vector<int> v;
  int idx, d;
  long long c;
  bool valid;
  string s;
  int w;
  Q() {}
  void eat() {
    cin >> d >> s >> c;
    reverse((s).begin(), (s).end());
    long long tmp = 1;
    for (int i = (0); i < (int)(s.size()); i++) v.push_back(F(s[i]));
    idx = nq++;
    valid = true;
  }
  void Nor(int b, int len) {
    for (int i = (len); i < (int)(v.size()); i++)
      if (v[i] > 0) {
        valid = false;
        return;
      }
    while (v.size() > len) v.pop_back();
    while (v.size() < len) v.push_back(0);
    w = 0;
    for (int j = 0, e = 1; j < len; j++, e *= b + 1) {
      int d = (v[j] == -1 ? b : v[j]);
      w += d * e;
    }
  }
  bool operator<(const Q &q) const { return d < q.d; }
} q[N];
long long ans[N];
const int M = 14348907;
long long dp[M];
int main() {
  for (int i = (2); i <= (int)(100); i++) {
    bool some = false;
    for (int j = (2); j < (int)(i); j++) {
      some |= (i % j == 0);
    }
    if (!some) p.push_back(i);
  }
  for (int i = (0); i < (int)(p.size()); i++) {
    long long t = 1;
    int j = i;
    while (j < p.size() && t * p[j] <= BDD) t *= p[j++];
    base.push_back(t);
    st.push_back(i);
    ed.push_back(j);
    i = j - 1;
  }
  nb = base.size();
  cin >> n;
  for (int i = (0); i < (int)(n); i++) cin >> a[i];
  int m;
  cin >> m;
  for (int i = (0); i < (int)(m); i++) q[i].eat();
  sort(q, q + nq);
  memset(ans, -1, sizeof(ans));
  for (int iq = 0, b = 2; iq < nq;) {
    while (b < q[iq].d) ++b;
    int s = iq;
    int e = iq;
    while (e < nq && q[e].d == b) ++e;
    iq = e;
    int first = n, len = 0, z = 1;
    while (first > 0) {
      first /= b;
      z *= b + 1;
      len++;
    }
    for (int j = (s); j < (int)(e); j++) {
      q[j].Nor(b, len);
    }
    for (int ib = (0); ib < (int)(nb); ib++) {
      long long MOD = base[ib];
      for (int i = (0); i < (int)(z); i++) {
        static int d[20];
        int p = -1;
        int k = 0;
        int k2 = 0;
        int q;
        for (int first = i, j = 0, e = 1, e2 = 1; j < len;
             j++, e *= b, e2 *= b + 1) {
          d[j] = first % (b + 1);
          first /= b + 1;
          if (d[j] == b && p == -1) {
            p = j;
            q = e2;
            k2 = i - q * b;
            break;
          } else {
            k += e * d[j];
          }
        }
        if (p == -1) {
          dp[i] = (k < n ? a[k] % MOD : 1LL);
        } else {
          dp[i] = 1LL;
          for (int u = (0); u < (int)(b); u++) {
            int j = k2 + q * u;
            dp[i] *= dp[j];
            if (dp[i] >= MOD) dp[i] %= MOD;
          }
        }
      }
      for (int j = (s); j < (int)(e); j++)
        if (ans[q[j].idx] == -1) {
          long long tmp = (dp[q[j].w] + q[j].c % MOD);
          if (tmp >= MOD) tmp %= MOD;
          for (int k = (st[ib]); k < (int)(ed[ib]); k++) {
            if (ans[q[j].idx] == -1 && tmp % p[k] == 0) {
              ans[q[j].idx] = p[k];
              break;
            }
          }
        }
    }
  }
  for (int iq = (0); iq < (int)(nq); iq++) cout << ans[iq] << endl;
  return 0;
}
