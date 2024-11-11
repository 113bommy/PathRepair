#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void smin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void smax(T &a, T b) {
  if (a < b) a = b;
}
const int inf = 1 << 29;
const int maxn = 100000 + 100;
const int K = 1000;
int n, t;
vector<int> v[maxn];
int dp[K], odp[K];
int main() {
  ios_base::sync_with_stdio(false);
  int ans = 0;
  cin >> n >> t;
  for (int z = 0, _n = (int)(t); z < _n; z++) {
    int r, c;
    cin >> r >> c;
    r = n - r, c--;
    if (r > K) {
      ans += 3;
      continue;
    }
    v[c].push_back(r);
  }
  for (int i = 0, _n = (int)(n); i < _n; i++)
    sort((v[i]).begin(), (v[i]).end());
  for (int i = 0, _n = (int)(n + 1); i < _n; i++) {
    memcpy(odp, dp, sizeof dp);
    int mnv = *min_element(odp, odp + K);
    int rem = (int((v[i]).size()));
    for (int j = 0, _n = (int)(K); j < _n; j++) {
      while (rem && v[i][(int((v[i]).size())) - rem] < j) rem--;
      dp[j] = min(i && j + 1 < K ? odp[j + 1] : inf,
                  mnv + j * (j + 1) / 2 + (j ? 2 : 0)) +
              rem * 3;
    }
  }
  cout << dp[0] + ans << endl;
  { return 0; }
}
