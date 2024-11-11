#include <bits/stdc++.h>
using namespace std;
long long t, n, u, v, m, q, l, r, ql, qr, k, d, c;
const int N = 2e5 + 500;
const int M = 2e2 + 5;
const long long mod = 1e9 + 7;
const bool JUDGE = false;
int A[N], B[N], C[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (JUDGE) {
    freopen("grader.in", "r", stdin);
    freopen("grader0.out", "w", stdout);
  }
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> A[i + 1];
  for (long long i = 0; i < n; i++) cin >> B[i + 1];
  for (long long i = 0; i < n; i++) C[B[i + 1]] = i + 1;
  for (long long i = 1; i < n + 1; i++) A[i] = C[A[i]];
  int j;
  for (long long i = 1; i < n + 1; i++) {
    if (A[i] > A[i - 1])
      j = i;
    else
      break;
  }
  cout << n - j << '\n';
  return 0;
}
