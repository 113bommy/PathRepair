#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100000 + 10;
int N;
long long x[MAX_N], y[MAX_N];
long long calc(long long *a, int N) {
  long long ret = 0, sum = 0;
  for (int i = 0; i < N; ++i) {
    ret += a[i] * a[i] * N;
    sum += a[i];
  }
  ret -= sum * sum;
  return ret;
}
void solve() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];
  cout << calc(x, N) + calc(y, N) << endl;
}
int main() {
  solve();
  return 0;
}
