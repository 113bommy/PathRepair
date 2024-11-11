#include <bits/stdc++.h>
using namespace std;
long long N, M, K, Max;
long long A[200], B[200];
long long w[200][200], err[200][200];
void read() {
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      cin >> w[i][j];
      Max = max(Max, w[i][j]);
    }
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
void solve() {
  for (int i = 0; i < N; i++) A[i] = w[i][0];
  for (int i = 0; i < M; i++) B[i] = w[0][i] - A[0];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) err[i][j] = abs(A[i] + B[j] - w[i][j]);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) K = gcd(K, err[i][j]);
  if (K) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (K <= w[i][j]) {
          cout << "NO" << endl;
          return;
        }
  }
  if (!K) K = Max + 1;
  cout << "YES" << endl << K << endl;
  for (int i = 0; i < N; i++)
    cout << (A[i] <= 0 ? (K - A[i]) % K : A[i]) << ' ';
  cout << endl;
  for (int i = 0; i < M; i++)
    cout << (B[i] <= 0 ? (K - B[i]) % K : B[i]) << ' ';
  cout << endl;
}
int main() {
  read();
  solve();
  return 0;
}
