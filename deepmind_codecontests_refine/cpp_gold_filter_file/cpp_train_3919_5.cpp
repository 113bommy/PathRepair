#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;
int n, x[N];
char c[N];
vector<pair<int, int>> segs;
long long ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  int last = -1;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> c[i];
    if (c[i] == 'G') {
      segs.emplace_back(last, i);
      last = i;
    }
  }
  segs.emplace_back(last, n);
  for (auto p : segs) {
    int l, r;
    tie(l, r) = p;
    int res = 0;
    vector<int> rs, bs;
    for (int i = l + 1; i < r; i++) {
      if (c[i] == 'R')
        rs.push_back(i);
      else
        bs.push_back(i);
    }
    if (l != -1 && r != n) {
      res = x[r] - x[l];
      if (!rs.empty()) {
        int rsub = max(x[rs.front()] - x[l], x[r] - x[rs.back()]);
        for (int i = 1; i < rs.size(); i++)
          rsub = max(x[rs[i]] - x[rs[i - 1]], rsub);
        res += x[r] - x[l] - rsub;
      }
      if (!bs.empty()) {
        int bsub = max(x[bs.front()] - x[l], x[r] - x[bs.back()]);
        for (int i = 1; i < bs.size(); i++)
          bsub = max(x[bs[i]] - x[bs[i - 1]], bsub);
        res += x[r] - x[l] - bsub;
      }
      if (!rs.empty() && !bs.empty())
        res = min((!rs.empty()) * (x[r] - x[l]) + (!bs.empty()) * (x[r] - x[l]),
                  res);
    } else {
      if (l != -1) {
        if (!rs.empty()) res += x[rs.front()] - x[l];
        if (!bs.empty()) res += x[bs.front()] - x[l];
      }
      if (r != n) {
        if (!rs.empty()) res += x[r] - x[rs.back()];
        if (!bs.empty()) res += x[r] - x[bs.back()];
      }
      res += (!rs.empty() ? x[rs.back()] - x[rs.front()] : 0) +
             (!bs.empty() ? x[bs.back()] - x[bs.front()] : 0);
    }
    ans += res;
  }
  cout << ans;
}
