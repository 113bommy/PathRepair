#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
inline int add(int a, int b) {
  if ((a += b) >= mod) a -= mod;
  return a;
}
inline int mult(int a, int b) { return a * b % mod; }
inline int dec(int a, int b) {
  if ((a -= b) < 0) a += mod;
  return a;
}
inline int power(int a, int b) {
  int out = 1;
  while (b) {
    if (b & 1) out = mult(out, a);
    a = mult(a, a);
    b >>= 1;
  }
  return out;
}
namespace polynomial {
vector<int> Mult(vector<int> A, vector<int> B, int n, int m) {
  vector<int> ret(n + m - 1, 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) ret[i + j] = add(ret[i + j], mult(A[i], B[j]));
  return ret;
}
vector<int> Mult(vector<int> A, vector<int> B) {
  return Mult(A, B, A.size(), B.size());
}
vector<int> Add(vector<int> A, vector<int> B) {
  vector<int> ret;
  ret.resize(max(A.size(), B.size()));
  for (int i = 0; i < ret.size(); i++) {
    if (i < A.size()) ret[i] = A[i];
    if (i < B.size()) ret[i] = add(ret[i], B[i]);
  }
  return ret;
}
vector<int> inverse(vector<int> f, int len) {
  vector<int> ret;
  if (len == 1) {
    ret.push_back(power(f[0], mod - 2));
    return ret;
  }
  vector<int> h = inverse(f, (len + 1) >> 1);
  int tlen = 1;
  while (tlen < (len << 1)) tlen <<= 1;
  ret.resize(tlen);
  vector<int> h2 = Mult(Mult(h, h), f);
  h2.resize(tlen);
  h.resize(tlen);
  for (int i = 0; i < tlen; i++) ret[i] = dec(mult(2, h[i]), h2[i]);
  ret.resize(len);
  return ret;
}
vector<int> inverse(vector<int> A) { return inverse(A, A.size()); }
vector<int> derivative(vector<int> A) {
  vector<int> ret;
  ret.resize(A.size() - 1);
  for (int i = 1; i < A.size(); i++) ret[i - 1] = mult(i, A[i]);
  return ret;
}
vector<int> integral(vector<int> A) {
  vector<int> ret;
  ret.resize(A.size() + 1);
  for (int i = 0; i < A.size(); i++)
    ret[i + 1] = mult(A[i], power(i + 1, mod - 2));
  ret[0] = 0;
  return ret;
}
vector<int> ln(vector<int> A, int len) {
  A = integral(Mult(inverse(A), derivative(A)));
  A.resize(len);
  return A;
}
vector<int> ln(vector<int> f) { return ln(f, f.size()); }
vector<int> exp(vector<int> f, int n) {
  vector<int> ret;
  if (n == 1) {
    ret.push_back(1);
    return ret;
  }
  vector<int> h = exp(f, (n + 1) >> 1);
  h.resize(n);
  vector<int> l = ln(h);
  ret.resize(n);
  l[0] = dec(add(f[0], 1), l[0]);
  for (int i = 1; i < n; i++) l[i] = dec(f[i], l[i]);
  ret = Mult(h, l);
  ret.resize(n);
  return ret;
}
vector<int> exp(vector<int> f) { return exp(f, f.size()); }
vector<int> Power(vector<int> f, int k) {
  int a = -1, b = -1;
  for (int i = 0; i < f.size(); i++) {
    if (f[i] != 0) {
      a = f[i];
      b = i;
      break;
    }
  }
  if (a == -1) return f;
  int ia = power(a, mod - 2);
  vector<int> g(f.size());
  if (b * k >= g.size()) {
    for (int i = 0; i < g.size(); i++) g[i] = 0;
    return g;
  }
  for (int i = b; i < f.size(); i++) g[i - b] = mult(f[i], ia);
  g = ln(g);
  for (int i = 0; i < g.size(); i++) g[i] = mult(g[i], k);
  g = exp(g);
  a = power(a, k);
  for (int i = 0; i < b * k; i++) f[i] = 0;
  for (int i = b * k; i < g.size(); i++) f[i] = mult(g[i - b * k], a);
  return f;
}
pair<vector<int>, vector<int> > division(vector<int> f, vector<int> g, int n,
                                         int m) {
  f.resize(n + 1);
  g.resize(m + 1);
  vector<int> rf = f, rg = g, q;
  reverse(rf.begin(), rf.end());
  reverse(rg.begin(), rg.end());
  rf.resize(n - m + 1);
  rg = inverse(rg, n - m + 1);
  q = Mult(rf, rg);
  q.resize(n - m + 1);
  reverse(q.begin(), q.end());
  vector<int> r, tmp = Mult(q, g);
  r.resize(m);
  for (int i = 0; i < m; i++) r[i] = dec(f[i], tmp[i]);
  return make_pair(q, r);
}
inline pair<vector<int>, vector<int> > division(vector<int> f, vector<int> g) {
  if (f.size() < g.size()) return make_pair(vector<int>(1, 0), f);
  return division(f, g, f.size() - 1, g.size() - 1);
}
inline vector<int> getremainder(vector<int> f, vector<int> g) {
  if (f.size() < g.size()) return f;
  return division(f, g, f.size() - 1, g.size() - 1).second;
}
}  // namespace polynomial
using namespace polynomial;
namespace linearrecursion {
vector<int> c, a;
inline int linearrecursion(vector<int> g, vector<int> st, int n) {
  int k = g.size();
  reverse(g.begin(), g.end());
  g.push_back(1);
  for (int i = 0; i < k; i++) g[i] = dec(0, g[i]);
  c.push_back(1);
  a.push_back(0);
  a.push_back(1);
  while (n) {
    if (n & 1) c = getremainder(Mult(c, a), g);
    a = getremainder(Mult(a, a), g);
    n >>= 1;
  }
  int ans = 0;
  c.resize(k);
  for (int i = 0; i < k; i++) ans = add(ans, mult(st[i], c[i]));
  return ans;
}
}  // namespace linearrecursion
namespace BM {
vector<int> seq[3010];
int fail[3010], cnt = 0, delta[3010];
inline vector<int> BM(vector<int> P, int n) {
  vector<int> R1;
  cnt = 0;
  seq[0].clear();
  for (int i = 0; i < n; i++) {
    int tval = 0;
    for (int j = 0; j < seq[cnt].size(); j++)
      tval = add(tval, mult(seq[cnt][j], P[i - j - 1]));
    delta[i] = dec(P[i], tval);
    if (tval == P[i]) continue;
    fail[cnt] = i;
    ++cnt;
    seq[cnt].clear();
    if (cnt == 1)
      for (int j = 0; j <= i; j++) seq[cnt].push_back(0);
    else {
      R1.clear();
      int mxpos = cnt - 2;
      for (int j = cnt - 3; j >= 0; j--)
        if ((int)seq[mxpos].size() - fail[mxpos] > (int)seq[j].size() - fail[j])
          mxpos = j;
      int tmp = mult(delta[i], power(delta[fail[mxpos]], mod - 2));
      for (int j = 0; j < i - fail[mxpos] - 1; j++) R1.push_back(0);
      R1.push_back(tmp);
      for (int j = 0; j < seq[mxpos].size(); j++)
        R1.push_back(dec(0, mult(tmp, seq[mxpos][j])));
      seq[cnt] = Add(seq[cnt - 1], R1);
    }
  }
  return seq[cnt];
}
}  // namespace BM
char s[210];
int n, f[610][210][210], done[610];
const int maxlen = 610;
int main() {
  scanf("%s%d", s + 1, &n);
  int m = strlen(s + 1);
  f[0][1][m] = 1;
  for (int i = 1; i < maxlen; i++) {
    done[i] = mult(done[i - 1], 26);
    for (int j = 0; j <= m; j++) {
      for (int k = m + 1; k >= j; k--) {
        if (s[j] == s[k]) {
          if (j + 1 <= k - 1)
            f[i][j + 1][k - 1] = add(f[i][j + 1][k - 1], f[i - 1][j][k]);
          else
            done[i] = add(done[i], f[i - 1][j][k]);
          f[i][j][k] = add(f[i][j][k], mult(f[i - 1][j][k], 25));
        } else {
          if (j == k)
            done[i] = add(done[i], mult(f[i - 1][j][k], 2));
          else {
            f[i][j + 1][k] = add(f[i][j + 1][k], f[i - 1][j][k]);
            f[i][j][k - 1] = add(f[i][j][k - 1], f[i - 1][j][k]);
          }
          f[i][j][k] = add(f[i][j][k], mult(f[i - 1][j][k], 24));
        }
      }
    }
  }
  vector<int> seqs(maxlen << 1);
  for (int i = m; i < (maxlen << 1); i++) {
    if (i & 1) {
      seqs[i] = mult(done[i >> 1], 26);
      for (int j = 1; j <= m; j++) seqs[i] = add(seqs[i], f[i >> 1][j][j]);
    } else {
      seqs[i] = done[i >> 1];
    }
  }
  printf("%d\n", linearrecursion::linearrecursion(BM::BM(seqs, maxlen << 1),
                                                  seqs, n + m));
  return 0;
}
