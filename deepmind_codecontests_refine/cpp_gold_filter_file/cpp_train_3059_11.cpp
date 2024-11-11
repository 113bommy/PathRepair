#include <bits/stdc++.h>
using namespace std;
long long int i, N, k, p, j, Ans;
int main() {
  cin >> N;
  for (i = 1; i < N; i++) {
    bool ok = false;
    p = 1;
    for (j = 1; j <= N - 2; j++) {
      p *= i;
      if ((p - 1) % N == 0) {
        ok = true;
        break;
      }
      p %= N;
    }
    p *= i;
    if (ok == false && ((p - 1)) % N == 0) Ans++;
  }
  cout << Ans << endl;
  return 0;
}
