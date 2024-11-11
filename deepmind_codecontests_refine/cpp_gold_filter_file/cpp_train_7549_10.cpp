#include <bits/stdc++.h>
using namespace std;
int l[100010], r[100010], cnt[100010], p[100010], c[100010];
vector<int> b[100010];
struct cv {
  int x, y;
  friend bool operator<(cv p, cv q) { return p.x > q.x; }
} hf, dd;
int main() {
  int n, m, x, y, ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &l[i], &r[i]);
    cnt[r[i]]++;
    b[l[i]].push_back(r[i]);
  }
  priority_queue<cv> q;
  for (int i = 1; i <= n; i++) {
    hf.x = cnt[i];
    hf.y = i;
    q.push(hf);
  }
  for (int i = 1; i <= n; i++) {
    hf = q.top();
    q.pop();
    if (hf.x != 0) {
      ans = -1;
      break;
    }
    if ((!q.empty()) && q.top().x == 0) {
      ans = -1;
      break;
    }
    c[i] = hf.y;
    for (int i = 0; i < b[hf.y].size(); i++) {
      cnt[b[hf.y][i]]--;
      dd.y = b[hf.y][i];
      dd.x = cnt[b[hf.y][i]];
      q.push(dd);
    }
  }
  if (ans == -1) {
    printf("%d\n", ans);
    return 0;
  }
  for (int i = 1; i < n; i++) p[c[i]] = c[i + 1];
  for (int i = 0; i < m; i++) {
    if (p[l[i]] == r[i]) ans = i + 1;
  }
  printf("%d\n", ans);
  return 0;
}
