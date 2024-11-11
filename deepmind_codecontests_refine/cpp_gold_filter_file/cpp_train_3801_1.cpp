#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 10;
const int INF = 1e9 + 7;
vector<pair<long long, long long> > ans;
inline void solve(void) {
  long long x;
  cin >> x;
  ans.push_back(make_pair(x, 1));
  for (long long m = (2); m < (2e6 + 1); m++) {
    long long get = (m * m * (m + 1)) / 2;
    get = get - ((m * (m + 1) * (2LL * m + 1LL)) / 6);
    long long tmp = x + get;
    long long div1 = (m * (m + 1)) / 2;
    if (tmp % div1 == 0) {
      long long n = tmp / div1;
      if (n > 0 && n >= m) ans.push_back(make_pair(n, m));
    }
  }
  int num = 0;
  for (int i = (0); i < (ans.size()); i++) num++;
  for (int i = (ans.size() - 1); i >= (0); i--) {
    if (ans[i].first != ans[i].second) {
      num++;
    }
  }
  cout << num << endl;
  for (int i = (0); i < (ans.size()); i++)
    cout << ans[i].second << " " << ans[i].first << endl;
  for (int i = (ans.size() - 1); i >= (0); i--) {
    if (ans[i].first != ans[i].second) {
      cout << ans[i].first << " " << ans[i].second << endl;
    }
  }
  return;
}
void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
int main(int argc, const char* argv[]) {
  init();
  solve();
  return 0;
}
