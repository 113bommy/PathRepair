#include <bits/stdc++.h>
using namespace std;
inline long long Phi(long long X) {
  register long long Return;
  Return = X;
  register long long i;
  for (i = 2; i * i <= X; i++) {
    if (X % i == 0) {
      while (X % i == 0) {
        X /= i;
      }
      Return = Return / i * (i - 1);
    }
  }
  if (X > 1) {
    Return = Return / X * (X - 1);
  }
  return Return;
}
int main(void) {
  register long long i;
  register long long N, K;
  cin >> N >> K;
  for (i = 1; i <= K; i++) {
    N = Phi(N);
    if (N == 1) {
      break;
    }
  }
  cout << N % 1000000007 << endl;
  return 0;
}
