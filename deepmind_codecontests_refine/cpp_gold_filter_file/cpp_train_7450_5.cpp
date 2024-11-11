#include <bits/stdc++.h>
using namespace std;
long long s(long long N, long long K) {
  if (N == 1) return 1;
  long long len = (1LL << N) - 1;
  if (K == (len + 1) / 2) return N;
  if (K < (len + 1) / 2) return s(N - 1, K);
  return s(N - 1, K - (len + 1) / 2);
}
int main() {
  long long N, K;
  while (cin >> N >> K) cout << s(N, K) << endl;
}
