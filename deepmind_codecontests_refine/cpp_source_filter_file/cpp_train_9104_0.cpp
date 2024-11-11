#include <bits/stdc++.h>
using namespace std;
int n, a[100002];
pair<int, int> nxt[20][100002];
vector<pair<int, int>> st;
void prec() {
  int nxt[2] = {-1, -1};
  for (int i = n - 1; i >= 0; --i)
    ::nxt[0][i].first = nxt[0], ::nxt[0][i].second = nxt[1], nxt[a[i]] = i;
  for (int d = 1; d < 20; ++d)
    for (int i = 0; i < n; ++i) {
      if (::nxt[d - 1][i].first != -1)
        ::nxt[d][i].first = ::nxt[d - 1][::nxt[d - 1][i].first].first;
      else
        ::nxt[d][i].first = -1;
      if (::nxt[d - 1][i].second != -1)
        ::nxt[d][i].second = ::nxt[d - 1][::nxt[d - 1][i].second].second;
      else
        ::nxt[d][i].second = -1;
    }
}
int getnextf(int c, int second) {
  if (!a[c]) second--;
  for (int d = 0; second >= (1 << d); ++d) {
    if (second & (1 << d)) {
      c = nxt[d][c].first;
      if (c == -1) break;
    }
  }
  return c;
}
int getnexts(int c, int second) {
  if (a[c]) second--;
  for (int d = 0; second >= (1 << d); ++d) {
    if (second & (1 << d)) {
      c = nxt[d][c].second;
      if (c == -1) break;
    }
  }
  return c;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) (cin >> a[i]), --a[i];
  int w = a[n - 1];
  prec();
  for (int second = 1; second <= n; ++second) {
    int cp = 0, np = 1, t[2] = {0, 0};
    while (np && np != n) {
      np = getnextf(cp, second) + 1;
      if (!np || np - cp >= 2 * second) {
        np = getnexts(cp, second) + 1;
        if (np && np - cp < 2 * second) ++t[1];
      } else
        ++t[0];
      cp = np;
    }
    if (cp == n && t[w] > t[!w]) st.push_back(make_pair(t[w], second));
  }
  sort(st.begin(), st.end());
  cout << st.size();
  for (auto i : st) cout << '\n' << i.first << ' ' << i.second;
  return 0;
}
