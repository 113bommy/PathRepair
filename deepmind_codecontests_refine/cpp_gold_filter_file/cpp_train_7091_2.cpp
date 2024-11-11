#include <bits/stdc++.h>
using namespace std;
long long n, m, p, i, d, z, x, j, k, ip, v, s;
char c;
vector<vector<long long> > M;
vector<long long> A[26];
long long D[26], P[26];
vector<vector<long long> > mult(vector<vector<long long> > A,
                                vector<vector<long long> > B) {
  long long i, j, k;
  vector<vector<long long> > C;
  C.resize(p);
  for (i = 0; i < p; i++) {
    C[i].resize(p);
    for (j = 0; j < p; j++)
      for (k = 0, C[i][j] = 0; k < p; k++)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % 12345;
  }
  return C;
}
vector<vector<long long> > be(vector<vector<long long> > V, long long e) {
  vector<vector<long long> > A;
  long long i;
  if (!e) {
    A.resize(p);
    for (i = 0; i < p; i++) {
      A[i].resize(p);
      A[i][i] = 1;
    }
    return A;
  }
  A = be(V, e / 2);
  A = mult(A, A);
  if (e & 1) A = mult(A, M);
  return A;
}
int main() {
  scanf("%I64d%I64d", &n, &m);
  for (i = 0; i < 26; i++) P[i] = 1;
  for (i = 0, p = 1; i < m; i++) {
    cin >> c;
    scanf("%I64d", &x);
    A[c - 'A'].push_back(x);
    p *= x;
    P[c - 'A'] *= x;
  }
  M.clear();
  M.resize(p);
  for (i = 0; i < p; i++) {
    M[i].resize(p);
    for (j = d = 0, x = i; j < 26; j++)
      if (A[j].size()) {
        D[d++] = x % P[j];
        x /= P[j];
      }
    for (j = z = 0; j < 26; j++)
      if (A[j].size()) {
        D[z] = (D[z] + 1) % P[j];
        for (k = ip = d = 0, v = 1; k < 26; k++)
          if (A[k].size()) {
            ip += v * D[d++];
            v *= P[k];
          }
        M[i][ip]++;
        D[z] = (D[z] + P[j] - 1) % P[j];
        z++;
      }
  }
  M = be(M, n);
  for (i = s = 0; i < p; i++) {
    for (j = d = 0, x = i; j < 26; j++)
      if (A[j].size()) {
        D[d++] = x % P[j];
        x /= P[j];
      }
    for (j = d = 0; j < 26; j++)
      if (A[j].size()) {
        for (k = 0; k < A[j].size() && D[d] % A[j][k]; k++)
          ;
        d++;
        if (k == A[j].size()) break;
      }
    if (j == 26) s = (s + M[i][0]) % 12345;
  }
  printf("%I64d", s);
  return 0;
}
