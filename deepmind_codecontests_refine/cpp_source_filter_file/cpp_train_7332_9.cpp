#include <bits/stdc++.h>
using namespace std;
int X[1010], Y[1010], P[1010];
double D[1010];
int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i] >> P[i];
    D[i] = 1.0 * X[i] * X[i] + 1.0 * Y[i] * Y[i];
  }
  long long l = 0, r = 500000000;
  K = 1000000 - K;
  while (r != l) {
    long long m = (l + r + 1) / 2;
    long long cnt = 0;
    for (int i = 0; i < N; ++i)
      if (m > D[i]) cnt += P[i];
    if (cnt >= K)
      r = m - 1;
    else
      l = m;
  }
  if (l = 500000000)
    cout << -1 << endl;
  else
    printf("%.10lf\n", sqrt(l));
}
