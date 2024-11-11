#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
struct RMQ {
  int dp[(1 << (18))][(18) + 2], G[(1 << (18))], XX, O = -1;
  void ini(int *A, int n) {
    if (!XX++)
      for (int k(1); k < (1 << (18)); k++) G[k] = O += (!(k & (k - 1)));
    for (int i(0); i < n; i++) dp[i][0] = i;
    for (int k(1); k < k - (1 << k) + n + 1; k++)
      for (int i(0); i < n + 1 - (1 << k); i++)
        if (A[dp[i][k - 1]] < A[dp[i + (1 << (k - 1))][k - 1]])
          dp[i][k] = dp[i][k - 1];
        else
          dp[i][k] = dp[i + (1 << (k - 1))][k - 1];
  }
  int qy(int *A, int L, int R) {
    int j(G[R - L + 1]);
    if (A[dp[L][j]] <= A[dp[R - (1 << j) + 1][j]]) return A[dp[L][j]];
    return A[dp[R - (1 << j) + 1][j]];
  }
} L;
struct RMX {
  int dp[(1 << (18))][(18) + 2], G[(1 << (18))], XX, O = -1;
  void ini(int *A, int n) {
    if (!XX++)
      for (int k(1); k < (1 << (18)); k++) G[k] = O += (!(k & (k - 1)));
    for (int i(0); i < n; i++) dp[i][0] = i;
    for (int k(1); k < k - (1 << k) + n + 1; k++)
      for (int i(0); i < n + 1 - (1 << k); i++)
        if (A[dp[i][k - 1]] > A[dp[i + (1 << (k - 1))][k - 1]])
          dp[i][k] = dp[i][k - 1];
        else
          dp[i][k] = dp[i + (1 << (k - 1))][k - 1];
  }
  int qy(int *A, int L, int R) {
    int j(G[R - L + 1]);
    if (A[dp[L][j]] >= A[dp[R - (1 << j) + 1][j]]) return dp[L][j];
    return dp[R - (1 << j) + 1][j];
  }
} R;
struct SA {
  int sa[(1 << (18))], R[(1 << (18))], C[(1 << (18))], s[(1 << (18)) << 1],
      t[(1 << (18)) << 1], p[(1 << (18))], S[(1 << (18))], U[(1 << (18))];
  void ss(int n, int m, int *s, int *t, int *p) {
    int A = t[n - 1] = 0, c = *R = -1, *r = s + n, x, y;
    for (int i = n - 2; ~i; --i)
      t[i] = s[i] ^ s[i + 1] ? s[i] > s[i + 1] : t[i + 1];
    for (int i(1); i < n; i++) R[i] = t[i - 1] && !t[i] ? (p[A] = i, A++) : -1;
    memset(sa, -1, n * 4), memset(S, 0, 4 * m);
    for (int i(0); i < n; i++) ++S[s[i]];
    for (int i(0); i < m; i++)
      if (i) S[i] += S[i - 1];
    for (int i(0); i < m; i++) U[i] = S[i] - 1;
    for (int i = A - 1; ~i; --i) sa[U[s[p[i]]]--] = p[i];
    for (int i(1); i < m; i++) U[i] = S[i - 1];
    for (int i(0); i < n; i++)
      if (sa[i] > 0 && t[sa[i] - 1]) sa[U[s[sa[i] - 1]]++] = sa[i] - 1;
    for (int i(0); i < m; i++) U[i] = S[i] - 1;
    for (int i = n - 1; ~i; --i)
      if (sa[i] > 0 && !t[sa[i] - 1]) sa[U[s[sa[i] - 1]]--] = sa[i] - 1;
    for (int i(0); i < n; i++)
      if (~(x = R[sa[i]])) {
        if (c < 1 || p[x + 1] - p[x] != p[y + 1] - p[y])
          ++c;
        else
          for (int j = p[x], k = p[y]; j <= p[x + 1]; ++j, ++k)
            if ((s[j] << 1 | t[j]) ^ (s[k] << 1 | t[k])) {
              ++c;
              break;
            }
        r[y = x] = c;
      }
    if (c + 1 < A)
      ss(A, c + 1, r, t + n, p + A);
    else
      for (int i(0); i < A; i++) sa[r[i]] = i;
    for (int i(0); i < A; i++) r[i] = p[sa[i]];
    memset(sa, -1, n * 4), memset(S, 0, 4 * m);
    for (int i(0); i < n; i++) ++S[s[i]];
    for (int i(0); i < m; i++)
      if (i) S[i] += S[i - 1];
    for (int i(0); i < m; i++) U[i] = S[i] - 1;
    for (int i = A - 1; ~i; --i) sa[U[s[r[i]]]--] = r[i];
    for (int i(1); i < m; i++) U[i] = S[i - 1];
    for (int i(0); i < n; i++)
      if (sa[i] > 0 && t[sa[i] - 1]) sa[U[s[sa[i] - 1]]++] = sa[i] - 1;
    for (int i(0); i < m; i++) U[i] = S[i] - 1;
    for (int i = n - 1; ~i; --i)
      if (sa[i] > 0 && !t[sa[i] - 1]) sa[U[s[sa[i] - 1]]--] = sa[i] - 1;
  }
  void sx(int N, char *r) {
    int m, h = *C = 0, M = *max_element(r, r + ++N);
    memset(R, 0, 4 * M + 4);
    for (int i(0); i < N; i++) R[(int)r[i]] = 1;
    for (int i(0); i < M; i++) R[i + 1] += R[i];
    for (int i(0); i < N; i++) s[i] = R[(int)r[i]] - 1;
    m = R[M];
    ss(N, m, s, t, p);
    for (int i(0); i < N; i++) R[sa[i]] = i;
    for (int i(0); i < N - 1; i++) {
      while (i + h < N && sa[R[i] - 1] + h < N &&
             s[i + h] == s[sa[R[i] - 1] + h])
        ++h;
      if ((C[(int)R[i]] = h)) --h;
    }
  }
} Z;
vector<pair<int, int> > o;
char s[(1 << (18))];
int N, F[(1 << (18))], B[(1 << (18))], P[(1 << (18))], S, E, z;
int qy(int f, int b) {
  f = F[f], b = B[b];
  if (f > b) swap(f, b);
  return L.qy(Z.C, f + 1, b);
}
bool ok(int t) {
  if (!t) return 1;
  if (t > E) return 0;
  int a = P[z = R.qy(P, 0, E - t)];
  return a >= t;
}
int bs(int B = 0, int E = int(1e9 + 1)) {
  int M;
  while (B < E)
    if (!ok(M = (B + E) >> 1))
      E = M;
    else
      B = M + 1;
  return max(0, B - 1);
}
void go(int I) {
  int a = qy(I, I), b = I - a + 1, e = I + a - 1, l, t;
  E = b;
  l = bs(0, min(E, N - e - 1) + 1), t = 2 * l + e - b + 1;
  if (t > S) {
    S = t, ok(l), o.clear();
    if (l) o.push_back({z, z + l - 1});
    o.push_back({b, e});
    if (l) o.push_back({N - 1 - l + 1, N - 1});
  }
}
int main(void) {
  scanf("%s", s), N = strlen(s), strcpy(s + N + 1, s),
                  reverse(s + N + 1, s + 2 * N + 1), s[N] = 63,
                  Z.sx(N * 2 + 1, s), L.ini(Z.C, N * 2 + 2);
  for (int i(0); i < 2 * N + 2; i++)
    if (Z.sa[i] < N)
      F[Z.sa[i]] = i;
    else if (Z.sa[i] > N)
      B[N - 1 - (Z.sa[i] - N - 1)] = i;
  for (int i(0); i < N; i++) P[i] = qy(i, N - 1);
  R.ini(P, N);
  for (int i(0); i < N; i++) go(i);
  printf("%lu\n", o.size());
  for (auto &h : o) printf("%d %d\n", h.first + 1, h.second - h.first + 1);
  return 0;
}
