#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, a, r, m;
  cin >> n >> a >> r >> m;
  m = min(m, a + r);
  vector<int64_t> h(n);
  for (int64_t& hi : h) cin >> hi;
  sort(h.begin(), h.end());
  vector<int64_t> pref(n);
  pref[0] = h[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + h[i];
  }
  int64_t result = 1e18;
  auto improve = [&](int i, int64_t target) {
    int64_t sumPrev = i == 0 ? 0 : pref[i - 1];
    int64_t prevDiff = i * target - sumPrev;
    int64_t sumNext = pref[n - 1] - sumPrev;
    int64_t nextDiff = sumNext - (n - i) * target;
    int64_t curResult = prevDiff > nextDiff
                            ? nextDiff * m + (prevDiff - nextDiff) * a
                            : prevDiff * m + (nextDiff - prevDiff) * r;
    result = min(result, curResult);
  };
  for (int i = 0; i < n; i++) {
    improve(i, h[i]);
  }
  int64_t average = pref[n - 1] / n;
  int i = lower_bound(h.begin(), h.end(), average) - h.begin();
  improve(i, average);
  average++;
  i = lower_bound(h.begin(), h.end(), average) - h.begin();
  improve(i, average);
  cout << result << "\n";
}
