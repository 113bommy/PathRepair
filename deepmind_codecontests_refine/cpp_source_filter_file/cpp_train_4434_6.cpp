#include <bits/stdc++.h>
using namespace std;
int T = 1;
long long N;
int main() {
  cin >> N;
  vector<long long> x(N);
  vector<long long> y(N);
  for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  long long ans = 0, s = 0, k = 0;
  for (int i = 1; i < N; i++) {
    k +=
        i * (x[i] - x[i - 1]) * (x[i] - x[i - 1]) + 2 * (s * (x[i] - x[i - 1]));
    s += (x[i] - x[i - 1]);
    ans += k;
  }
  s = 0;
  k = 0;
  for (int i = 1; i < N; i++) {
    k +=
        i * (y[i] - y[i - 1]) * (y[i] - y[i - 1]) + 2 * (s * (y[i] - y[i - 1]));
    s += (y[i] - y[i - 1]) * i;
    ans += k;
  }
  cout << ans << "\n";
  return 0;
}
