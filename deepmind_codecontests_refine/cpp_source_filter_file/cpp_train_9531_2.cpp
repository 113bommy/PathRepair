#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  while (x != 0 && y != 0)
    if (x > y)
      x %= y;
    else
      y %= x;
  return x + y;
}
long long a1[1500];
bool cmp(size_t x, size_t y) { return a1[x] < a1[y]; }
bool isLess(pair<vector<int>, long long> &lhs,
            pair<vector<int>, long long> &rhs) {
  if (lhs.first.size() < rhs.first.size()) return true;
  if (lhs.first.size() > rhs.first.size()) return false;
  return lhs.second < rhs.second;
}
int main() {
  int n;
  long long k, kk;
  cin >> n >> k;
  kk = k;
  if (k == 1) {
    long long m;
    cin >> m;
    int r = 1;
    for (int i = 2; i <= n; i++) {
      long long y;
      cin >> y;
      if (y < m) {
        m = y;
        r = i;
      }
    }
    cout << 1 << endl << r << endl;
    return 0;
  }
  map<long long, vector<int> > z;
  for (int i = 0; i < n; i++) {
    cin >> a1[i];
    z[gcd(a1[i], k)].push_back(i);
  }
  for (auto it = z.begin(); it != z.end(); it++)
    sort(it->second.begin(), it->second.end(), cmp);
  map<long long, pair<vector<int>, long long> > m;
  m[k] = {{}, 0};
  for (auto itz = z.begin(); itz != z.end(); itz++)
    for (auto itm = m.begin(); itm != m.end(); itm++) {
      long long curr = itm->first;
      pair<vector<int>, long long> ans = itm->second;
      for (int i = 0; i < itz->second.size(); i++) {
        int index = (itz->second)[i];
        long long a = a1[index];
        long long g = gcd(curr, a);
        if (g == 1) break;
        curr /= g;
        ans.first.push_back(index);
        ans.second += a;
        auto it2 = m.find(curr);
        if (it2 == m.end()) {
          m[curr] = ans;
        } else if (isLess(ans, it2->second))
          swap(it2->second, ans);
      }
    }
  if (m.find(1) == m.end()) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> &ans = m.find(1)->second.first;
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i] + 1);
  return 0;
}
