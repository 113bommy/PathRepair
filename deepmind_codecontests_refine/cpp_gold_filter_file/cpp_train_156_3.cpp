#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long robots[100001];
  long long N, K;
  cin >> N >> K;
  for (long i = 0; i < N; i++) {
    cin >> robots[i];
  }
  for (long i = 0; i < N; i++) {
    if (K - (i + 1) <= 0) {
      cout << robots[K - 1];
      return 0;
    } else {
      K = K - (i + 1);
    }
  }
  return 0;
}
