#include <bits/stdc++.h>
using namespace std;
const int three = 3;
int int_pow(int b, int e) {
  if (e == 0) return 1;
  return int_pow(b, e / 2) * int_pow(b, e / 2) * (e % 2 == 0 ? 1 : b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  int m = n / 2;
  vector<vector<int> > r;
  for (int i = 0; i < (n); ++i) {
    int l, m, w;
    cin >> l >> m >> w;
    r.push_back({l, m, w});
  }
  map<pair<int, int>, pair<int, int> > dp;
  for (int i = 0; i < (int_pow(3, m)); ++i) {
    pair<int, int> cursum = make_pair(0, 0);
    int cc = i;
    int sum = 0;
    for (int j = 0; j < (m); ++j) {
      int md = cc % three;
      cc /= three;
      if (md == 0) {
        cursum.first += r[j][1];
        cursum.second += r[j][2];
        sum += r[j][1] + r[j][2];
      }
      if (md == 1) {
        cursum.first += r[j][1] - r[j][0];
        cursum.second -= r[j][0];
        sum += r[j][0] + r[j][1];
      }
      if (md == 2) {
        cursum.first -= r[j][0];
        cursum.second += r[j][2] - r[j][0];
        sum += r[j][0] + r[j][2];
      }
    }
    if (dp.find(cursum) != dp.end()) {
      if (dp[cursum].second < sum) {
        dp[cursum] = make_pair(i, sum);
      }
    } else {
      dp[cursum] = make_pair(i, sum);
    }
  }
  pair<int, int> bestsol;
  int bestsolution = -1e9;
  for (int i = 0; i < (int_pow(3, n - m)); ++i) {
    pair<int, int> cursum = make_pair(0, 0);
    int cc = i;
    int sum = 0;
    for (int j = m; j < (n); ++j) {
      int md = cc % three;
      cc /= three;
      if (md == 0) {
        cursum.first -= r[j][1];
        cursum.second -= r[j][2];
        sum += r[j][1] + r[j][2];
      }
      if (md == 1) {
        cursum.first -= r[j][1] - r[j][0];
        cursum.second += r[j][0];
        sum += r[j][0] + r[j][1];
      }
      if (md == 2) {
        cursum.first += r[j][0];
        cursum.second -= r[j][2] - r[j][0];
        sum += r[j][2] + r[j][0];
      }
    }
    auto x = dp.find(cursum);
    if (x != dp.end()) {
      int totsum = sum + x->second.second;
      if (totsum > bestsolution) {
        bestsol = make_pair(x->second.first, i);
        bestsolution = totsum;
      }
    }
  }
  if (bestsolution != -1e9) {
    int cc = bestsol.first;
    for (int j = 0; j < (m); ++j) {
      int md = cc % three;
      cc /= three;
      if (md != 0) cout << "L";
      if (md != 1) {
        cout << "W";
      }
      if (md != 2) cout << "M";
      cout << endl;
    }
    cc = bestsol.second;
    for (int j = m; j < (n); ++j) {
      int md = cc % three;
      cc /= three;
      if (md != 0) cout << "L";
      if (md != 1) {
        cout << "W";
      }
      if (md != 2) cout << "M";
      cout << endl;
    }
    return 0;
  }
  cout << "Impossible" << endl;
  return 0;
}
