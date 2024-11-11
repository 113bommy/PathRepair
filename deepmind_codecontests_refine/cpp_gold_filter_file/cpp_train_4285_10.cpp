#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long POW(long long a, long long b, long long MMM = MOD) {
  long long ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) {
  if (a == 0 || b == 0) return a + b;
  return a * (b / gcd(a, b));
}
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int ddx[] = {-1, -2, 1, -2, 2, -1, 2, 1}, ddy[] = {-2, -1, -2, 1, -1, 2, 1, 2};
vector<vector<long long> > operator*(const vector<vector<long long> >& A,
                                     const vector<vector<long long> >& B) {
  int n = A.size(), m = A[0].size();
  int N = B.size(), M = B[0].size();
  vector<vector<long long> > C =
      vector<vector<long long> >(n, vector<long long>(M));
  if (m != N) return C;
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    for (int(j) = (0); (j) <= (M - 1); (j) += (1)) {
      for (int(k) = (0); (k) <= (m - 1); (k) += (1))
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    }
  }
  return C;
}
vector<vector<long long> > mul(vector<vector<long long> >& A, int k) {
  if (k == 1) return A;
  if (k & 1) return mul(A, k - 1) * A;
  vector<vector<long long> > t = mul(A, k / 2);
  return t * t;
}
int c0, c1;
int a[100];
int n, K;
int main() {
  scanf("%d%d", &n, &K);
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) scanf("%d", a + i);
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) {
    if (a[i] == 0)
      c0++;
    else
      c1++;
  }
  long long p, q = n * (n - 1) / 2;
  q = POW(q, K);
  int T = min(c0, c1);
  vector<vector<long long> > A =
      vector<vector<long long> >(T + 1, vector<long long>(T + 1));
  for (int(k) = (0); (k) <= (T); (k) += (1)) {
    if (k < T) A[k][k + 1] = (c0 - k) * (c1 - k);
    A[k][k] =
        (c0 - k) * k + (c1 - k) * k + c0 * (c0 - 1) / 2 + c1 * (c1 - 1) / 2;
    if (k > 0) A[k][k - 1] = k * k;
  }
  A = mul(A, K);
  int k = 0;
  for (int(i) = (0); (i) <= (c0 - 1); (i) += (1))
    if (a[i] == 1) k++;
  p = A[k][0];
  printf("%lld\n", (p * POW(q, MOD - 2)) % MOD);
}
