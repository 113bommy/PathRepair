#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ans = 0;
  int N, K, A[200000];
  string S;
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  cin >> S;
  int i, j = 0;
  while (j < N) {
    i = j;
    while (j < N && S[j] == S[i]) j++;
    sort(A + i, A + j, greater<int>());
    for (int k = 0; k < K; k++) {
      ans += A[i++];
      if (i == j) break;
    }
  }
  cout << ans << endl;
}
