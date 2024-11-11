#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int N, K, ans, quant, index, x;
  cin >> N >> K;
  for (long long int i = 0; i < K; i++) {
    cin >> x;
    if (i == 0) {
      ans = N % x;
      quant = N / x;
      index = i + 1;
      continue;
    }
    if (N % x < ans) {
      ans = N % x;
      quant = N / x;
      index = i + 1;
    }
  }
  cout << index << " " << quant << endl;
  return 0;
}
