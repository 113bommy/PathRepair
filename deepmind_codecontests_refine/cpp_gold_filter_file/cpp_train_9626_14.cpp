#include <bits/stdc++.h>
using namespace std;
int N, M;
void solve() {
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  cin >> M;
  vector<int> B(M);
  for (int i = 0; i < M; i++) cin >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int sA = N * 3;
  int sB = M * 3;
  int maxdiff = sA - sB;
  int maxA = sA;
  int maxB = sB;
  for (int i = 0; i < M; i++) {
    int sz = upper_bound(A.begin(), A.end(), B[i]) - A.begin();
    int scA = sz * 2 + (A.size() - sz) * 3;
    int scB = (i + 1) * 2 + (M - i - 1) * 3;
    if (scA - scB > maxdiff) {
      maxdiff = scA - scB;
      maxA = scA, maxB = scB;
    } else if (scA - scB == maxdiff) {
      if (scA > maxA) maxA = scA, maxB = scB;
    }
  }
  cout << maxA << ":" << maxB << endl;
  return;
}
int main() {
  solve();
  return 0;
}
