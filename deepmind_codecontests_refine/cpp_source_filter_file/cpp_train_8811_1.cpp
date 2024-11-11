#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(32);
  int n, k;
  cin >> n >> k;
  int prev = 0;
  vector<vector<pair<int, int> > > dp(1);
  dp[0] = vector<pair<int, int> >({{0, 0}});
  for (int i = 1; i <= k; i++) {
    int l, r;
    cin >> l >> r;
    vector<vector<pair<int, int> > > ndp(2 * i + 1);
    for (int j = 0; j <= 2 * i; j++) {
      vector<pair<int, int> > tmp;
      if (j >= 2 && r - l + 1 >= 2) {
        for (auto x : dp[j - 2]) {
          if (j % 2 == 1) {
            int lo = max(-n, x.first - (r - l + 1) - (l - prev - 1));
            int hi = min(n, x.second + (r - l - 1) - (l - prev - 1));
            if (lo <= hi) tmp.push_back({lo, hi});
          } else {
            int lo = max(-n, x.first + (r - l - 1) + (l - prev - 1));
            int hi = min(n, x.second + (r - l + 1) + (l - prev - 1));
            if (lo <= hi) tmp.push_back({lo, hi});
          }
        }
      }
      if (j >= 1 && j <= 2 * i - 1) {
        for (auto x : dp[j - 1]) {
          if (j % 2 == 0) {
            int lo = max(-n, x.first - (r - l + 1) - (l - prev - 1));
            int hi = min(n, x.second + (r - l - 1) - (l - prev - 1));
            if (lo <= hi) tmp.push_back({lo, hi});
          } else {
            int lo = max(-n, x.first - (r - l - 1) + (l - prev - 1));
            int hi = min(n, x.second + (r - l + 1) + (l - prev - 1));
            if (lo <= hi) tmp.push_back({lo, hi});
          }
        }
      }
      if (j <= 2 * i - 2) {
        for (auto x : dp[j]) {
          if (j % 2 == 1) {
            int lo = max(-n, x.first - (r - l + 1) - (l - prev - 1));
            int hi = min(n, x.second - (r - l + 1) - (l - prev - 1));
            if (lo <= hi) tmp.push_back({lo, hi});
          } else {
            int lo = max(-n, x.first + (r - l + 1) + (l - prev - 1));
            int hi = min(n, x.second + (r - l + 1) + (l - prev - 1));
            if (lo <= hi) tmp.push_back({lo, hi});
          }
        }
      }
      if (tmp.empty()) continue;
      sort(tmp.begin(), tmp.end());
      int st = tmp[0].first;
      int en = tmp[0].second;
      for (int i = 1; i < tmp.size(); i++) {
        if (tmp[i].first <= en + 1)
          en = max(en, tmp[i].second);
        else {
          ndp[j].push_back({st, en});
          st = tmp[i].first;
          en = tmp[i].second;
        }
      }
      ndp[j].push_back({st, en});
    }
    dp = ndp;
    prev = r;
  }
  for (int i = 0; i <= 2 * k; i++) {
    for (auto &x : dp[i]) {
      if (i % 2 == 0) {
        x.first = max(-n, x.first + 2 * n - prev);
        x.second = min(n, x.second + 2 * n - prev);
      } else {
        x.first = max(-n, x.first - 2 * n + prev);
        x.second = min(n, x.second - 2 * n + prev);
      }
      if (x.first <= 0 && x.second >= 0) {
        cout << "Full\n" << i << '\n';
        exit(0);
      }
    }
  }
  cout << "Hungry\n";
  return 0;
}
