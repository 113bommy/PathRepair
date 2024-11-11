#include <bits/stdc++.h>
using namespace std;
const long long pinf = 1e18 + 4;
const long long ninf = -pinf;
const long long N = 1005;
long long X[N];
long long Y[N];
long long A[N];
long long S[N];
void init(long long n) {
  long long i;
  for (long long i = 0; i < n; i++) A[i] = i, S[i] = 1;
}
long long root(long long i) {
  while (A[i] != i) {
    A[i] = A[A[i]];
    i = A[i];
  }
  return i;
}
void con(long long x, long long y) {
  long long rx = root(x);
  long long ry = root(y);
  if (rx == ry) return;
  if (S[rx] < S[ry]) {
    S[ry] += S[rx];
    A[rx] = A[ry];
    S[rx] = 0;
  } else {
    S[rx] += S[ry];
    A[ry] = A[rx];
    S[ry] = 0;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> X[i] >> Y[i];
  set<long long> R;
  init(n);
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (X[i] == X[j] || Y[i] == Y[j]) con(i, j);
      R.insert(X[i]);
      R.insert(Y[i]);
    }
  }
  set<long long> S;
  for (long long i = 0; i < n; i++) S.insert(A[i]);
  cout << S.size() - 1;
  long long c = 1;
}
