#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  int N, M, K;
  cin >> N >> K >> M;
  vector<long long> A(N);
  long long s = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    s += A[i];
  }
  sort(A.begin(), A.end());
  long double res = (long double)(s + min(M, N * K)) / (long double)N;
  for (int i = 0; i < min(N - 1, M); i++) {
    s -= A[i];
    long long tp = s + min((N - i - 1) * K, M - i - 1);
    long double avg = (long double)tp / (long double)(N - i - 1);
    res = max(res, avg);
  }
  cout << fixed << setprecision(20) << res << endl;
}
