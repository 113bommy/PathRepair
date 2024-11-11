#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int N;
int P[MAXN];
long double A[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> P[i];
  long double ans = 1, x = 1;
  for (int i = 0; i < N; i++) {
    ans *= P[i] / 100.0;
    A[i] = 1 - P[i] / 100.0;
    x *= (1 - A[i]);
  }
  ans *= N;
  for (int i = 1; i <= 180000; i++) {
    int idx = 0;
    long double val = x / (1 - A[0]) * A[0] * P[0] / 100.0;
    for (int j = 1; j < N; j++) {
      long double cur = x / (1 - A[j]) * A[j] * P[j] / 100.0;
      if (val < cur) idx = j, val = cur;
    }
    ans += val * (i + N);
    x /= (1 - A[idx]);
    A[idx] *= (1 - P[idx] / 100.0);
    x *= (1 - A[idx]);
  }
  printf("%.10f\n", (double)ans);
  return 0;
}
