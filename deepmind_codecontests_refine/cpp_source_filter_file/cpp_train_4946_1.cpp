#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<int, int> p[100000];
pair<int, int> p_[100000];
multiset<pair<int, int> > s, s_;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    p[i].first = a + c;
    p[i].second = b + d;
    s.insert(p[i]);
    p_[i].first = p[i].second;
    p_[i].second = p[i].first;
    s_.insert(p_[i]);
  }
  sort(p, p + n);
  sort(p_, p_ + n);
  long long ans = (~0ull) >> 1;
  for (int l = 0; l <= k; l++) {
    for (int r = 0; l + r <= k; r++) {
      for (int i = 0; i < l; i++) {
        if (p[i].first < p[l].first) {
          s.erase(s.find(p[i]));
          s_.erase(s_.find(make_pair(p[i].second, p[i].first)));
        }
      }
      for (int i = 0; i < r; i++) {
        if (p[n - 1 - i].first > p[n - 1 - r].first) {
          s.erase(s.find(p[n - 1 - i]));
          s_.erase(s_.find(make_pair(p[n - 1 - i].second, p[n - 1 - i].first)));
        }
      }
      for (int t = 0; l + r + t <= k; t++) {
        int d = k - l - r - t;
        pair<int, int> tp[k], dp[k];
        int tps = 0, dps = 0;
        auto tite = s_.begin();
        auto dite = s_.rbegin();
        for (int i = 0; i < t; i++) {
          tite++;
        }
        for (int i = 0; i < d; i++) {
          dite++;
        }
        auto tit = s_.begin();
        auto dit = s_.rbegin();
        for (int i = 0; i < t; i++) {
          if (tit->first < tite->first) {
            tp[tps++] = *tit;
          }
          tit++;
        }
        for (int i = 0; i < d; i++) {
          if (dit->first < dite->first) {
            dp[dps++] = *dit;
          }
          dit++;
        }
        for (int i = 0; i < tps; i++) {
          s.erase(s.find(make_pair(tp[i].second, tp[i].first)));
          s_.erase(s_.find(tp[i]));
        }
        for (int i = 0; i < dps; i++) {
          s.erase(s.find(make_pair(dp[i].second, dp[i].first)));
          s_.erase(s_.find(dp[i]));
        }
        long long A = s.begin()->first - s.rbegin()->first;
        if (A & 1) {
          A++;
        }
        if (!A) {
          A = 2;
        }
        long long B = s_.begin()->first - s_.rbegin()->first;
        if (B & 1) {
          B++;
        }
        if (!B) {
          B = 2;
        }
        ans = min(ans, A * B);
        for (int i = 0; i < tps; i++) {
          s.insert(make_pair(tp[i].second, tp[i].first));
          s_.insert(tp[i]);
        }
        for (int i = 0; i < dps; i++) {
          s.insert(make_pair(dp[i].second, dp[i].first));
          s_.insert(dp[i]);
        }
      }
      for (int i = 0; i < l; i++) {
        if (p[i].first < p[l].first) {
          s.insert(p[i]);
          s_.insert(make_pair(p[i].second, p[i].first));
        }
      }
      for (int i = 0; i < r; i++) {
        if (p[n - 1 - i].first > p[n - 1 - r].first) {
          s.insert(p[n - 1 - i]);
          s_.insert(make_pair(p[n - 1 - i].second, p[n - 1 - i].first));
        }
      }
    }
  }
  cout << ans / 4 << endl;
}
