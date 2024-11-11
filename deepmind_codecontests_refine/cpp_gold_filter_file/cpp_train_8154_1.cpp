#include <bits/stdc++.h>
using namespace std;
int n, u, r;
int A[40][40];
int B[40];
int K[40];
int P[40];
long long int res = LLONG_MIN;
inline long long int calc(int d) {
  long long int res = 0;
  for (int i = 1; i <= n; i++) res += (long long int)A[i][d] * K[i];
  return (res);
}
void doMagic(int d = 0, bool fl = false) {
  if (d == u) {
    res = max(res, calc(d));
    return;
  }
  if (!((u - d) & 1)) {
    res = max(res, calc(d));
  }
  for (int i = 1; i <= n; i++) A[i][d + 1] = A[P[i]][d] + r;
  doMagic(d + 1, false);
  if (fl) return;
  for (int i = 1; i <= n; i++) A[i][d + 1] = A[i][d] ^ B[i];
  doMagic(d + 1, true);
}
int main() {
  cin >> n >> u >> r;
  for (int i = 1; i <= n; i++) cin >> A[i][0];
  for (int i = 1; i <= n; i++) cin >> B[i];
  for (int i = 1; i <= n; i++) cin >> K[i];
  for (int i = 1; i <= n; i++) cin >> P[i];
  doMagic();
  cout << res;
  return (0);
}
