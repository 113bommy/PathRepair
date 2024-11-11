#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
pair<int, int> cars[N];
int gas[N], n, K, S, T;
bool gd(int cap) {
  int prv = 0;
  long long t = 0;
  for (int i = (0); i < (K); i++) {
    int d = gas[i] - prv, f = cap;
    if (d > f) return false;
    t += d * 2;
    f -= d;
    t -= min(d, f);
    prv = gas[i];
  }
  return t <= T;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> K >> S >> T;
  for (int i = (0); i < (n); i++) cin >> cars[i].second >> cars[i].first;
  sort(cars, cars + n);
  for (int i = (0); i < (K); i++) cin >> gas[i];
  gas[K++] = S;
  sort(gas, gas + K);
  int st = 0, en = n - 1, mid, idx = -1;
  while (st <= en) {
    mid = st + (en - st) / 2;
    if (gd(cars[mid].first))
      idx = mid, en = mid - 1;
    else
      st = mid + 1;
  }
  if (idx == -1)
    cout << -1 << endl;
  else {
    int res = (1 << 29);
    for (int i = (idx); i < (n); i++) res = min(res, cars[i].second);
    cout << res << endl;
  }
  return 0;
}
