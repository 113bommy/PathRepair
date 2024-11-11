#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
array<long long int, 4> dp[1LL << 9];
pair<long long int, long long int> pdp[1LL << 9];
long long int get(std::vector<long long int> v) {
  long long int n = ((long long int)v.size()), i, j, ans = 0;
  for (auto x : v) ans += (1LL << (x - 1));
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int test = 1;
  while (test--) {
    long long int n, m, i, j, k;
    cin >> n >> m;
    std::vector<long long int> fr[n];
    long long int frm[n];
    for (i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      fr[i].resize(x);
      for (j = 0; j < x; j++) cin >> fr[i][j];
      frm[i] = get(fr[i]);
    }
    pair<long long int, std::vector<long long int> > p[m];
    long long int pm[m];
    for (i = 0; i < m; i++) {
      cin >> p[i].first;
      long long int x;
      cin >> x;
      p[i].second.resize(x);
      for (j = 0; j < x; j++) cin >> (p[i].second)[j];
      pm[i] = get(p[i].second);
    }
    for (i = 0; i < 1LL << 9; i++) pdp[i] = {1e18, -1};
    for (long long int mask = 0; mask < (1LL << 9); mask++) {
      for (j = 0; j < m; j++) {
        if ((mask & pm[j]) == mask) {
          if (pdp[mask].first > p[j].first) pdp[mask] = {p[j].first, j};
        }
      }
    }
    for (long long int mask = 0; mask < (1LL << 9); mask++) {
      long long int num = 0;
      for (j = 0; j < n; j++) {
        if ((mask & frm[j]) == frm[j]) num++;
      }
      dp[mask][0] = num;
      dp[mask][1] = 1e18;
      dp[mask][2] = -1;
      dp[mask][3] = -1;
      for (j = 0; j < m; j++) {
        long long int sub = ((mask ^ pm[j]) & mask);
        long long int price = p[j].first + pdp[sub].first;
        if (price < dp[mask][1]) {
          dp[mask][1] = price;
          dp[mask][2] = j;
          dp[mask][3] = pdp[sub].second;
        }
      }
    }
    long long int in1, in2, num = 0, price = 1e18;
    for (i = 0; i < 1LL << 9; i++) {
      if (dp[i][1] >= 1e18) continue;
      if (dp[i][0] > num) {
        num = dp[i][0];
        price = dp[i][1];
        in1 = dp[i][2];
        in2 = dp[i][3];
      } else if (dp[i][0] == num && dp[i][1] < price) {
        price = dp[i][1];
        in1 = dp[i][2];
        in2 = dp[i][3];
      }
    }
    assert(in1 != -1 && in2 != -1);
    if (in1 == in2) {
      price = 1e18;
      for (i = 0; i < m; i++) {
        if (in1 != i && p[i].first < price) price = p[i].first, in2 = i;
      }
    }
    cout << in1 + 1 << " " << in2 + 1;
  }
  cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms"
       << "\n";
  return 0;
}
