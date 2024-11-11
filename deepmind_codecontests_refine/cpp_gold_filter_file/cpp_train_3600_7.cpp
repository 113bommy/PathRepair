#include <bits/stdc++.h>
using namespace std;
const long long int maxN = 5e4 + 226;
long long int N, _time[maxN][7], ct, covered, arr[maxN], narr[maxN],
    currentMinus[maxN];
signed main() {
  cin >> N;
  for (long long int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  if (N % 7 == 0) {
    long long int ans = 0;
    for (long long int i = 0; i < N; i++) {
      if ((i % 7) == 6) continue;
      if ((arr[i] - 1) * (N) + i < (arr[ans] - 1) * (N) + i) ans = i;
    }
    cout << ans + 1 << endl;
    return 0;
  }
  for (long long int t = 0; t < 7 * N; t++) {
    if (t % 7 == 6) continue;
    currentMinus[t % N]++;
    _time[t % N][currentMinus[t % N]] = t;
  }
  _time[N - 1][0] = -1 - N;
  for (long long int i = 0; i < N - 1; i++) _time[i][0] = i - N;
  long long int ans = 0;
  long long int ti, ta;
  for (long long int i = 0; i < N; i++) {
    ti = arr[i] / 6 * (7 * N) + _time[i][arr[i] % 6];
    if (arr[i] % 6 == 0) ti = (arr[i] - 6) / 6 * (7 * N) + _time[i][6];
    ta = arr[ans] / 6 * (7 * N) + _time[ans][arr[ans] % 6];
    if (arr[ans] % 6 == 0) ta = (arr[ans] - 6) / 6 * (7 * N) + _time[ans][6];
    if (ti < ta) ans = i;
  }
  cout << ans + 1 << endl;
}
