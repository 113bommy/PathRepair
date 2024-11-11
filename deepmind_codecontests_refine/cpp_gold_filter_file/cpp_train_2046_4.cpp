#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = int(1e9);
const int MAX = int(1e6) + 1;
int prime[MAX + 2], primeFactorMax[MAX + 2], res;
void calc() {
  for (int i = 2; i < MAX; i++) {
    prime[i] = 1;
    primeFactorMax[i] = -1;
  }
  for (int i = 2; i < MAX; i++) {
    if (prime[i]) {
      for (int j = 2 * i; j < MAX; j += i) {
        prime[j] = 0;
      }
    }
  }
  primeFactorMax[1] = 1;
  for (int i = 2; i < MAX; i++) {
    if (prime[i]) {
      primeFactorMax[i] = i;
      for (int j = 2 * i; j < MAX; j += i) {
        primeFactorMax[j] = max(primeFactorMax[j], i);
      }
    }
  }
}
int main() {
  calc();
  int X2;
  cin >> X2;
  res = INF;
  for (int X1 = X2 - primeFactorMax[X2] + 1; X1 <= X2; X1++) {
    for (int X0 = X1 - primeFactorMax[X1] + 1; X0 <= X1 && X0 >= 3; X0++) {
      if (X0 > res) {
        break;
      }
      res = min(res, X0);
    }
  }
  cout << res << "\n";
  return 0;
}
