#include <bits/stdc++.h>
using namespace std;
int n, N, cnt, sum[1 << 12];
bool dp[1 << 12][24];
vector<int> vc;
inline int biname(int mask) {
  int ret = 0;
  for (; mask; mask /= 2) ret++;
  return ret;
}
inline int count(int x) {
  int ret = 0;
  for (int i = 0; i < 24; i++)
    if (x & (1 << i)) ret++;
  return ret;
}
int main() {
  cin >> n;
  for (int x, i = 0; i < n; i++) {
    cin >> x;
    if (x == 1)
      cnt++;
    else if (x == 2) {
      cout << "NO" << endl;
      exit(0);
    } else
      vc.push_back(x);
  }
  sort(vc.begin(), vc.end());
  if (n == 1) {
    cout << (cnt == 1 ? "YES" : "NO") << endl;
    exit(0);
  }
  if (cnt < vc.size() || vc.size() == 0 || vc.back() != n) {
    cout << "NO" << endl;
    exit(0);
  }
  for (int i = 0; i < (1 << vc.size()); i++)
    for (int j = 0; j < vc.size(); j++)
      if (i & (1 << j)) sum[i] += vc[j];
  N = vc.size();
  dp[0][cnt] = 1;
  for (int mask = 0; mask < (1 << vc.size()); mask++)
    for (int j = 0; j <= cnt; j++) {
      int hlp = biname(mask);
      if (hlp == vc.size()) continue;
      if (dp[mask][j])
        for (int k = 0; k < (1 << vc.size()); k++)
          if ((mask & k) == k && sum[k] <= (vc[hlp] - 1) &&
              sum[k] + j >= (vc[hlp] - 1)) {
            int next = mask ^ k, need = vc[hlp] - sum[k] - 1;
            next |= (1 << hlp);
            if (need || count(k) > 1) dp[next][j + need] = 1;
          }
    }
  cout << (dp[(1 << (N - 1))][0] ? "YES" : "NO") << endl;
}
