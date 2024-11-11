#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int b[maxn], cnt[maxn], pos[maxn];
vector<int> ans[maxn];
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n + 1; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      cnt[b[i]]++;
    }
    int s = 0;
    for (int i = 1; i <= n + 1; i++)
      if (!cnt[i]) {
        s = i;
        break;
      }
    priority_queue<pair<int, int> > q1, q2;
    for (int i = 1; i <= n + 1; i++)
      if (cnt[i]) q1.push(make_pair(cnt[i], i));
    for (int i = 1; i <= n + 1; i++) ans[i].clear();
    for (int i = 1; i <= x; i++) {
      pair<int, int> now = q1.top();
      q1.pop();
      int t = now.first, p = now.second;
      ans[p].push_back(p);
      if (t > 1) q1.push(make_pair(t - 1, p));
      cnt[p]--;
    }
    for (int i = 1; i <= n + 1; i++)
      if (cnt[i]) q2.push(make_pair(cnt[i], -i));
    bool boom = 0;
    int last = n - y;
    for (int i = 1; i <= y - x; i++) {
      pair<int, int> now = q1.top();
      q1.pop();
      int t = now.first, p = now.second;
      pair<int, int> now2 = q2.top();
      q2.pop();
      int t2 = now2.first, p2 = -now2.second;
      if (p2 == p) {
        if (q2.empty()) {
          if (last) {
            ans[p].push_back(s);
            if (t > 1) q1.push(make_pair(t - 1, p));
            q2.push(now2);
            last--;
            i--;
            continue;
          } else {
            boom = 1;
            break;
          }
        }
        pair<int, int> now3 = q2.top();
        q2.pop();
        int t3 = now3.first, p3 = -now3.second;
        ans[p].push_back(p3);
        if (t > 1) q1.push(make_pair(t - 1, p));
        q2.push(now2);
        if (t3 > 1) q2.push(make_pair(t3 - 1, -p3));
      } else {
        ans[p].push_back(p2);
        if (t > 1) q1.push(make_pair(t - 1, p));
        if (t2 > 1) q2.push(make_pair(t2 - 1, -p2));
      }
    }
    if (boom)
      cout << "NO" << endl;
    else {
      while (!q1.empty()) {
        pair<int, int> now = q1.top();
        q1.pop();
        int t = now.first, p = now.second;
        for (int i = 1; i <= t; i++) ans[p].push_back(s);
      }
      cout << "YES" << endl;
      for (int i = 1; i <= n + 1; i++) pos[i] = 0;
      for (int i = 1; i <= n; i++) cout << ans[b[i]][pos[b[i]]++] << " ";
      cout << endl;
    }
  }
  return 0;
}
