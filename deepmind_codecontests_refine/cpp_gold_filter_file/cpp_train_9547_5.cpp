#include <bits/stdc++.h>
using namespace std;
unsigned long long n, m, A, B, C, w[3];
vector<unsigned long long> L[200000], U[200000];
pair<int, int> p[200000];
bool canbeA(unsigned long long x) { return x < n - 2; }
bool canbeB(unsigned long long x) { return x > 0 && x < n - 1; }
bool canbeC(unsigned long long x) { return x > 1; }
unsigned long long Comb(unsigned long long x) { return x * (x - 1) / 2; }
unsigned long long Sum(unsigned long long a, unsigned long long b) {
  return (a + b) * (b - a + 1) / 2;
}
unsigned long long calc(unsigned long long i, unsigned long long j,
                        unsigned long long k) {
  w[0] = i, w[1] = j, w[2] = k;
  sort(w, w + 3);
  return w[0] * A + w[1] * B + w[2] * C;
}
void solve() {
  for (unsigned long long i = 0; i < n; i++) {
    sort(L[i].begin(), L[i].end());
    sort(U[i].begin(), U[i].end());
  }
  unsigned long long sum[4] = {0};
  for (int i = 0; i < (int)n; i++) {
    if (canbeA(i)) sum[0] += Comb(n - i - 1) * A * i;
    if (canbeB(i)) sum[0] += (n - i - 1) * i * B * i;
    if (canbeC(i)) sum[0] += Comb(i) * C * i;
  }
  for (unsigned long long i = 0; i < n; i++) {
    for (unsigned long long j : U[i]) {
      if (canbeA(i) && canbeB(j)) {
        sum[1] += (A * i + B * j) * (n - j - 1) + Sum(j + 1, n - 1) * C;
      }
      if (canbeA(i) && canbeC(j)) {
        sum[1] += (A * i + C * j) * (j - i - 1) + Sum(i + 1, j - 1) * B;
      }
      if (canbeB(i) && canbeC(j)) {
        sum[1] += (B * i + C * j) * i + Sum(0, i - 1) * A;
      }
    }
  }
  for (unsigned long long i = 0; i < n; i++) {
    unsigned long long cntL = L[i].size(), cntU = U[i].size();
    for (int j = 0; j < (int)L[i].size(); j++) {
      unsigned long long v = L[i][j];
      if (canbeC(i)) {
        sum[2] += A * v * (cntL - j - 1) + B * v * j;
      }
      if (canbeB(i)) {
        sum[2] += A * v * cntU;
      }
    }
    for (int j = 0; j < (int)U[i].size(); j++) {
      unsigned long long v = U[i][j];
      if (canbeB(i)) {
        sum[2] += C * v * cntL;
      }
      if (canbeA(i)) {
        sum[2] += B * v * (cntU - j - 1) + C * v * j;
      }
    }
    sum[2] += Comb(cntL) * C * i + cntL * cntU * B * i + Comb(cntU) * A * i;
  }
  for (int i = 0; i < (int)m; i++) {
    int u, v;
    tie(u, v) = p[i];
    int s = 0, t = 0;
    while (s < (int)L[u].size() && t < (int)L[v].size()) {
      if (L[u][s] == L[v][t]) {
        sum[3] += calc(u, v, L[u][s]);
        s++;
        t++;
      } else if (L[u][s] < L[v][t]) {
        s++;
      } else {
        t++;
      }
    }
  }
  cout << sum[0] - (sum[1] - sum[2] + sum[3]) << endl;
}
void swap(unsigned long long& u, unsigned long long& v) {
  if (u < v) return;
  u ^= v;
  v ^= u;
  u ^= v;
}
int main() {
  cin >> n >> m >> A >> B >> C;
  for (unsigned long long i = 0, u, v; i < m; i++) {
    scanf("%I64d %I64d\n", &u, &v);
    swap(u, v);
    p[i] = make_pair(u, v);
    U[u].push_back(v);
    L[v].push_back(u);
  }
  solve();
  return 0;
}
