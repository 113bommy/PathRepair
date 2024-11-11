#include <bits/stdc++.h>
using namespace std;
const int MOD = 1 << 30;
const int _P = 257;
const int INF = 1000000000;
const int MAXN = 1000005;
const int SZ = 1 << 21;
int N, A[2 * SZ], C[MAXN], res = -1;
long long H[2 * MAXN], P[2 * MAXN];
string S, SS;
inline int get(int p, int l) {
  return (H[p + l] - H[p] * P[l] % MOD + MOD) % MOD;
}
bool comp(int a, int b) {
  int lo = 0, hi = N + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (get(a, mid) == get(b, mid))
      lo = mid;
    else
      hi = mid;
  }
  if (lo == N) return 0;
  return SS[a + lo] < SS[b + lo];
}
int rmq(int l, int r) {
  l += SZ, r += SZ + 1;
  int res = INF;
  for (; l < r; l /= 2, r /= 2) {
    if (l & 1) res = min(res, A[l++]);
    if (r & 1) res = min(res, A[--r]);
  }
  return res;
}
void init() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> S;
  N = S.size();
  SS = S + S;
  P[0] = 1;
  for (int i = 0; i < 2 * N; i++) {
    H[i + 1] = (H[i] * _P + SS[i]) % MOD;
    P[i + 1] = P[i] * _P % MOD;
    A[i + 1 + SZ] = A[i + SZ] + 2 * (SS[i] == '(') - 1;
  }
  for (int i = SZ - 1; i >= 0; i--) {
    A[i] = min(A[2 * i], A[2 * i + 1]);
  }
}
int main() {
  init();
  for (int i = 0; i < N; i++) {
    int k = rmq(i, i + N) - A[i + SZ];
    if (k >= min(A[N + SZ], 0) && (res < 0 || comp(i, res))) {
      res = i;
    }
  }
  for (int i = 0; i < -A[N + SZ]; i++) cout << "(";
  cout << SS.substr(res, N);
  for (int i = 0; i < A[N + SZ]; i++) cout << ")";
}
