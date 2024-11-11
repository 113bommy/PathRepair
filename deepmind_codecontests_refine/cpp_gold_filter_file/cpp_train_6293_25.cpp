#include <bits/stdc++.h>
using namespace std;
long double fact[100000];
long double prob[100005];
long double choose(int x, int y) {
  if (y < 0) return 0;
  if (x < y) return 0;
  return fact[x] / fact[y] / fact[x - y];
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cout << setprecision(12);
  fact[0] = 1;
  prob[0] = 1;
  for (int i = 1; i < m + 1; ++i) {
    fact[i] = i * fact[i - 1];
    prob[i] = prob[i - 1] * (k + 1 - i) / (m + 1 - i);
  }
  long double sum = 0;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) {
      sum += choose(n, i) * choose(n, j) * prob[n * (i + j) - i * j];
    }
  if (sum < 1e99)
    cout << sum << endl;
  else
    cout << "1e99" << endl;
}
