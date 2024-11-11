#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20020;
const int MAXT = 86400;
int n, m, t, a[MAXN], ans[MAXN], r, real_m, cnt[MAXN], last[MAXN];
queue<pair<int, int> > q;
set<pair<int, int> > cur_s;
int main() {
  cin >> n >> m >> t;
  for (int i = 0; i < n; ++i) {
    int hh, mm, ss;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    int s = hh * 60 * 60 + mm * 60 + ss;
    while (!q.empty() && q.front().first <= s) {
      int id = q.front().second;
      q.pop();
      --cnt[id];
      if (cnt[id] == 0) cur_s.erase(make_pair(last[id], id));
    }
    if (cur_s.size() >= m)
      ans[i] = cur_s.begin()->second;
    else
      ans[i] = ++r;
    q.push(make_pair(s + t, ans[i]));
    ++cnt[ans[i]];
    if (cnt[ans[i]] != 1) cur_s.erase(make_pair(last[ans[i]], ans[i]));
    last[ans[i]] = s;
    cur_s.insert(make_pair(last[ans[i]], ans[i]));
    real_m = max(real_m, (int)cur_s.size());
  }
  if (real_m < m)
    cout << "No solution" << endl;
  else {
    cout << r << endl;
    for (int i = 0; i < n; ++i) cout << ans[i] << endl;
  }
  return 0;
}
