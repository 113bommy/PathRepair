#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7, M = 1e9 + 7;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
int to(char c) {
  if (c == 'L')
    return 0;
  else if (c == 'R')
    return 1;
  else if (c == 'U')
    return 2;
  else
    return 3;
}
signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  ;
  int n, h, w;
  string s;
  cin >> n >> h >> w >> s;
  vector<pair<int, int> > evt1, evt2;
  {
    int mnx = 1, mxx = h, mny = 1, mxy = w;
    int cur_mnx = 1, cur_mxx = h, cur_mny = 1, cur_mxy = w;
    for (int i = 0; i < n * 2 && mnx <= mxx && mny <= mxy; i++) {
      int which = to(s[i % n]);
      if (dx[which] == 1) cur_mxx--, cur_mnx--;
      if (dx[which] == -1) cur_mnx++, cur_mxx++;
      if (dy[which] == 1) cur_mxy--, cur_mny--;
      if (dy[which] == -1) cur_mny++, cur_mxy++;
      if (cur_mnx > mnx) {
        if (i < n)
          evt1.emplace_back(which, i + 1);
        else
          evt2.emplace_back(which, i + 1);
        mnx = cur_mnx;
      }
      if (cur_mxx < mnx) {
        if (i < n)
          evt1.emplace_back(which, i + 1);
        else
          evt2.emplace_back(which, i + 1);
        mxx = cur_mxx;
      }
      if (cur_mny > mny) {
        if (i < n)
          evt1.emplace_back(which, i + 1);
        else
          evt2.emplace_back(which, i + 1);
        mny = cur_mny;
      }
      if (cur_mxy < mxy) {
        if (i < n)
          evt1.emplace_back(which, i + 1);
        else
          evt2.emplace_back(which, i + 1);
        mxy = cur_mxy;
      }
    }
  }
  auto add = [&](int& a, int b) {
    a += b;
    if (a >= M) a -= M;
  };
  int ans = 0;
  {
    int mnx = 1, mxx = h, mny = 1, mxy = w;
    for (pair<int, int> e : evt1) {
      int which = e.first;
      if (dx[which] == 1)
        mxx--, add(ans, (long long)(mxy - mny + 1) * e.second % M);
      if (dx[which] == -1)
        mnx++, add(ans, (long long)(mxy - mny + 1) * e.second % M);
      if (dy[which] == 1)
        mxy--, add(ans, (long long)(mxx - mnx + 1) * e.second % M);
      if (dy[which] == -1)
        mny++, add(ans, (long long)(mxx - mnx + 1) * e.second % M);
    }
    if (evt2.size()) {
      int i = -1, more = 0;
      while (mnx <= mxx && mny <= mxy) {
        if (++i == evt2.size()) i -= evt2.size(), add(more, n);
        pair<int, int> e = evt2[i];
        int which = e.first;
        if (dx[which] == 1)
          mxx--, add(ans, (long long)(mxy - mny + 1) * (e.second + more) % M);
        if (dx[which] == -1)
          mnx++, add(ans, (long long)(mxy - mny + 1) * (e.second + more) % M);
        if (dy[which] == 1)
          mxy--, add(ans, (long long)(mxx - mnx + 1) * (e.second + more) % M);
        if (dy[which] == -1)
          mny++, add(ans, (long long)(mxx - mnx + 1) * (e.second + more) % M);
      }
    }
    if (mnx <= mxx && mny <= mxy) return cout << -1 << endl, 0;
  }
  cout << ans << endl;
}
