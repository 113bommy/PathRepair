#include <bits/stdc++.h>
using namespace std;
const long long N = 1000 * 100 + 121, LG = 20;
long long Rank[LG][N];
pair<pair<int, int>, int> tmp[N];
pair<int, int> suf[N];
string s;
int n;
int lcp(int x, int y) {
  int ans = 0;
  for (int i = LG - 1; i >= 0; i--)
    if (Rank[i][x] == Rank[i][y]) {
      x += (1 << i);
      y += (1 << i);
      ans += (1 << i);
    }
  return ans;
}
struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    int x1 = a.first, y1 = a.second;
    int x2 = b.first, y2 = b.second;
    int l = lcp(x1, x2);
    l = min(l, y1 - x1);
    l = min(l, y2 - x2);
    if (l < y1 - x1 && l < y2 - x2) return (s[x1 + l] < s[x2 + l]);
    if (l == y1 - x1 && l == y2 - x2) return (a < b);
    return (l == y1 - x1);
  }
};
set<pair<int, int>, cmp> st;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int k;
  cin >> s >> k;
  n = s.size();
  for (int j = 0; j < n; j++) Rank[0][j] = s[j];
  for (int i = 1; i < LG; i++) {
    for (int j = 0; j < n; j++) {
      if (j + (1 << (i - 1)) >= n)
        tmp[j] = {{Rank[i - 1][j], -1}, j};
      else
        tmp[j] = {{Rank[i - 1][j], Rank[i - 1][j + (1 << (i - 1))]}, j};
    }
    sort(tmp, tmp + n);
    Rank[i][tmp[0].second] = 1;
    for (int j = 1; j < n; j++) {
      if (tmp[j].first == tmp[j - 1].first)
        Rank[i][tmp[j].second] = Rank[i][tmp[j - 1].second];
      else
        Rank[i][tmp[j].second] = j + 1;
    }
  }
  for (int i = 0; i < n; i++) st.insert({i, i + 1});
  pair<int, int> mn;
  while (k--) {
    if (st.empty()) {
      cout << "No such line.\n";
      return 0;
    }
    mn = *st.begin();
    st.erase(st.begin());
    if (mn.second < n) st.insert({mn.first, mn.second + 1});
  }
  cout << s.substr(mn.first, mn.second - mn.first) << "\n";
  return 0;
}
