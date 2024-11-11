#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 3;
int n;
vector<pair<int, int> > str;
int mxx1[maxn];
int mxxy1[maxn];
int mxx2[maxn];
int mxxy2[maxn];
pair<int, pair<int, int> > solve(int m) {
  vector<pair<int, int> > str1;
  vector<pair<int, int> > str2;
  for (auto p : str) {
    if (p.second > m) {
      str2.push_back(p);
    } else {
      str1.push_back(p);
    }
  }
  int n1 = str1.size();
  int n2 = str2.size();
  mxx1[0] = 0;
  for (int i = 1; i <= n1; i++) {
    mxx1[i] = max(mxx1[i - 1], m - str1[i - 1].second);
  }
  mxxy1[n1] = -maxn;
  for (int i = n1 - 1; i >= 0; i--) {
    mxxy1[i] = max(mxxy1[i + 1], str1[i].first - str1[i].second);
  }
  mxx2[n2] = 0;
  for (int i = n2 - 1; i >= 0; i--) {
    mxx2[i] = max(mxx2[i + 1], str2[i].second - m);
  }
  mxxy2[0] = -maxn;
  for (int i = 1; i <= n2; i++) {
    mxxy2[i] = max(mxxy2[i - 1], str2[i - 1].second - str2[i - 1].first);
  }
  int best = maxn;
  pair<int, int> s = {0, m};
  int p1 = 0;
  int p2 = 0;
  for (int y = (m == 0); y < maxn; y++) {
    while (p1 != n1 && str1[p1].first <= y) p1++;
    while (p2 != n2 && str2[p2].first <= y) p2++;
    int ans = 0;
    if (p1 > 0) {
      ans = max(ans, max(y - str1[0].first, mxx1[p1]));
    }
    if (p1 < n1) {
      ans = max(ans, mxxy1[p1] - y + m);
    }
    if (p2 > 0) {
      ans = max(ans, mxxy2[p1] - m + y);
    }
    if (p2 < n2) {
      ans = max(ans, max(str2[n2 - 1].first - y, mxx2[p1]));
    }
    if (ans < best) {
      best = ans;
      s.first = y;
    }
  }
  return {best, s};
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<string> s(n);
  str.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (auto j : s[i]) {
      if (j == 'B') {
        str[i].first++;
      } else {
        str[i].second++;
      }
    }
  }
  sort((str).begin(), (str).end());
  int l = 0, r = 5e5 + 1;
  while (l + 1 != r) {
    int m1 = l + (r - l) / 3;
    int a1 = solve(m1).first;
    int m2 = l + (r - l) * 2 / 3;
    int a2 = solve(m2).first;
    if (a1 > a2) {
      l = m1 + 1;
    } else if (a2 > a1) {
      r = m2;
    } else {
      l = m1;
      r = m2;
    }
  }
  pair<int, pair<int, int> > p = solve(l);
  cout << p.first << '\n';
  for (int i = 0; i < p.second.first; i++) {
    cout << 'B';
  }
  for (int i = 0; i < p.second.second; i++) {
    cout << 'N';
  }
  cout << '\n';
  return 0;
}
