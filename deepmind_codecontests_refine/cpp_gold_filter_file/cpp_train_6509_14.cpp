#include <bits/stdc++.h>
using namespace std;
int N, K, head, tail, q[200001];
long double t[200001], sum[200001], a[200001], b[200001], f[200001], g[200001];
int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++)
    cin >> t[i], sum[i] = sum[i - 1] + t[i], a[i] = a[i - 1] + sum[i] / t[i],
                 b[i] = b[i - 1] + 1 / t[i], f[i] = g[i] = a[i];
  for (int j = 2; j <= K; j++) {
    q[head = 1] = 0, q[tail = 2] = 1;
    f[1] = 1;
    for (int i = 2; i <= N; i++) {
      while (head < tail &&
             (g[q[head + 1]] - a[q[head + 1]] +
              sum[q[head + 1]] * b[q[head + 1]]) -
                     (g[q[head]] - a[q[head]] + sum[q[head]] * b[q[head]]) <=
                 b[i] * (sum[q[head + 1]] - sum[q[head]]))
        head++;
      f[i] =
          g[q[head]] + a[i] - a[q[head]] - sum[q[head]] * (b[i] - b[q[head]]);
      while (head < tail &&
             ((g[i] - a[i] + sum[i] * b[i]) -
              (g[q[tail]] - a[q[tail]] + sum[q[tail]] * b[q[tail]])) *
                     (sum[q[tail]] - sum[q[tail - 1]]) <=
                 ((g[q[tail]] - a[q[tail]] + sum[q[tail]] * b[q[tail]]) -
                  (g[q[tail - 1]] - a[q[tail - 1]] +
                   sum[q[tail - 1]] * b[q[tail - 1]])) *
                     (sum[i] - sum[q[tail]]))
        tail--;
      q[++tail] = i;
    }
    for (int i = 1; i <= N; i++) g[i] = f[i];
  }
  cout << f[N] << endl;
  return 0;
}
