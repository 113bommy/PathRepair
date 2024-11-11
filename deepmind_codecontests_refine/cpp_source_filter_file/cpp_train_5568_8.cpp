#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 + 5;
const long long mod = 1000 * 1000 * 1000 + 7;
int w[maxN], h[maxN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> w[i] >> h[i];
  int ans = mod;
  for (int i = 1; i < 20; i++) {
    int fl = 1, te = 0;
    vector<int> v;
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (min(h[j], w[j]) > i) {
        fl = 0;
        break;
      }
      sum += w[j];
      if (max(h[j], w[j]) <= i) {
        if (h[j] >= w[j]) continue;
        v.push_back(w[j] - h[j]);
        continue;
      }
      if (w[j] < h[j]) te++, sum -= w[j], sum += h[j];
    }
    if (te > n / 2 || fl == 0) continue;
    sort(v.begin(), v.end());
    while (te < n / 2 && v.size()) {
      sum -= v.back();
      v.pop_back();
      te++;
    }
    ans = min(ans, sum * i);
  }
  cout << ans << endl;
  return 0;
}
