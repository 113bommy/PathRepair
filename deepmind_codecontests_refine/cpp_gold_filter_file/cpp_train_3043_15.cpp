#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 200000 + 5;
const int inf = 0x3f3f3f3f;
vector<int> vec[maxn];
int par[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    for (int i = 0; i <= n; i++) {
      vec[i].clear();
    }
    int cnt[n + 5];
    for (int i = 0; i < n; i++) {
      cnt[i] = 1;
    }
    int sum = (n * (n - 1)) / 2;
    int nowmin = 1;
    int nowmax = n - 1;
    if (sum < d) {
      cout << "NO" << endl;
      continue;
    }
    while (sum > d) {
      if (nowmin >= nowmax) break;
      if (sum - d >= nowmax - nowmin) {
        sum -= (nowmax - nowmin);
        cnt[nowmax]--;
        nowmax--;
        cnt[nowmin]++;
        if (cnt[nowmin] == (1 << nowmin)) {
          nowmin++;
        }
      } else {
        int x = sum - d;
        sum -= (sum - d);
        cnt[nowmax]--;
        nowmax--;
        cnt[nowmax - x + 1]++;
      }
    }
    if (sum > d) {
      cout << "NO" << endl;
      continue;
    }
    int cntt = 1;
    vec[0].push_back(1);
    for (int i = 1; i <= nowmax; i++) {
      for (int j = 1; j <= cnt[i]; j++) {
        vec[i].push_back(++cntt);
        par[cntt] = vec[i - 1][(j - 1) / 2];
      }
    }
    cout << "YES" << endl;
    for (int i = 2; i <= cntt; i++) {
      cout << par[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
