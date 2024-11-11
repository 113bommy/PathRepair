#include <bits/stdc++.h>
using namespace std;
long long MOD[] = {1000000007LL, 1000000009LL};
long long INV[2][200000 + 5];
long long POT[2][200000 + 5];
long long pow(long long a, long long b, long long c) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % c;
    a = (a * a) % c;
    b >>= 1;
  }
  return ans;
}
long long modInverse(long long a, long long mod) {
  return pow(a, mod - 2, mod);
}
struct Hash {
  long long H[2];
  Hash() { memset(H, 0, sizeof(H)); }
  void add(long long p) {
    for (int i = 0; i < 2; ++i) H[i] = (H[i] * 27 + p) % MOD[i];
  }
  void add(Hash &x, int len) {
    if (len <= 0) return;
    for (int i = 0; i < 2; ++i) H[i] = (H[i] * POT[i][len] + x.H[i]) % MOD[i];
  }
};
Hash get(vector<Hash> &T, int lo, int hi) {
  if (lo > hi) return Hash();
  Hash a = T[hi + 1], b = T[lo];
  Hash c;
  for (int i = 0; i < 2; ++i) {
    c.H[i] = (a.H[i] - b.H[i] * POT[i][hi - lo + 1]) % MOD[i];
    if (c.H[i] < 0) c.H[i] += MOD[i];
  }
  return c;
}
void RESIZE(vector<pair<long long, long long> > &X) {
  X.resize(unique(X.begin(), X.end()) - X.begin());
}
int main() {
  POT[0][0] = POT[1][0] = 1;
  for (int j = 0; j < 2; ++j)
    for (int i = 0; i < 200000; ++i) POT[j][i + 1] = (POT[j][i] * 27) % MOD[j];
  INV[0][0] = INV[1][0] = 1;
  for (int i = 0; i < 2; ++i) INV[i][1] = pow(27, MOD[i] - 2, MOD[i]);
  for (int j = 0; j < 2; ++j)
    for (int i = 2; i <= 200000; ++i)
      INV[j][i] = (INV[j][i - 1] * INV[j][1]) % MOD[j];
  ios_base ::sync_with_stdio(0);
  int n;
  string s, t;
  while (cin >> n >> s >> t) {
    vector<Hash> a(1), b(1);
    Hash x, y;
    for (int i = 0; i < n; ++i) {
      x.add(s[i] - 'a' + 1);
      a.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
      y.add(t[i] - 'a' + 1);
      b.push_back(y);
    }
    vector<pair<long long, long long> > X, Y;
    for (int i = 0; i < n + 1; ++i)
      for (int c = 0; c < 26; ++c) {
        Hash p = get(a, 0, i - 1);
        p.add(c + 1);
        Hash q = get(a, i, n - 1);
        p.add(q, n - 1 - i + 1);
        X.push_back(make_pair(p.H[0], p.H[1]));
      }
    for (int i = 0; i < n + 1; ++i)
      for (int c = 0; c < 26; ++c) {
        Hash p = get(b, 0, i - 1);
        p.add(c + 1);
        Hash q = get(b, i, n - 1);
        p.add(q, n - 1 - i + 1);
        Y.push_back(make_pair(p.H[0], p.H[1]));
      }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    RESIZE(X);
    RESIZE(Y);
    set<pair<long long, long long> > SET;
    for (int i = 0; i < ((int)X.size()); ++i)
      if (binary_search(Y.begin(), Y.end(), X[i])) SET.insert(X[i]);
    printf("%d\n", ((int)SET.size()));
  }
}
