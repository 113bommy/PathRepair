#include <bits/stdc++.h>
using namespace std;
int A[2000005], I[2000005], O[200005], R[2000005], N, M, p, q, r;
int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    cin >> p >> q;
    A[p]++, A[p + q]--;
    if (p + q - 1 > R[p]) R[p] = p + q - 1, I[p] = i;
  }
  for (int i = 1; i <= N; i++) A[i] += A[i - 1];
  for (int i = 1; i <= N; i++) {
    if (R[i] > q) q = R[i], p = I[i];
    if (A[i] && r < i) r = q, O[p] = 1;
  }
  p = 0;
  for (int i = 1; i <= M; i++)
    if (!O[i]) A[++p] = i;
  cout << p << "\n";
  for (int i = 1; i <= p; i++) cout << A[i] << " ";
}
