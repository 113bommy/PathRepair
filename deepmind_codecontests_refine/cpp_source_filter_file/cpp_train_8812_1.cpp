#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, M, D, sol = -1;
  cin >> n >> k >> M >> D;
  for (int i = 0; i < D; i++) {
    long long t = n / (long double)(k * i + 1);
    if (t <= M)
      sol = max(sol, t * (i + 1));
    else
      sol = max(sol, M * (i + 1));
  }
  cout << sol << endl;
  return 0;
}
