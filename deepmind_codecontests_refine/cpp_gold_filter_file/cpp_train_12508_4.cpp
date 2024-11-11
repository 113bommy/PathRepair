#include <bits/stdc++.h>
using namespace std;
const int maxn = 200020;
priority_queue<int> q;
int pre[maxn], nxt[maxn], b[maxn], a[maxn], n, k, cnt, p1, p2, ans[maxn];
bool vis[maxn];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[a[i]] = i;
    pre[i] = i - 1;
    nxt[i] = i + 1;
    q.push(a[i]);
  }
  int tt = 0;
  while (!q.empty()) {
    tt++;
    int tp = q.top();
    q.pop();
    while (vis[b[tp]] && !q.empty()) {
      tp = q.top();
      q.pop();
    }
    if (vis[b[tp]] && q.empty()) break;
    int p = b[tp];
    vis[p] = true;
    ans[p] = tt % 2;
    cnt = 0;
    p1 = pre[b[tp]];
    while (p1 != 0 && cnt < k) {
      cnt++;
      ans[p1] = tt % 2;
      vis[p1] = true;
      nxt[pre[p1]] = nxt[p1];
      pre[nxt[p1]] = pre[p1];
      p1 = pre[p1];
    }
    cnt = 0;
    p2 = nxt[b[tp]];
    while (p2 != n + 1 && cnt < k) {
      cnt++;
      ans[p2] = tt % 2;
      vis[p2] = true;
      pre[nxt[p2]] = pre[p2];
      nxt[pre[p2]] = nxt[p2];
      p2 = nxt[p2];
    }
    nxt[p1] = nxt[p];
    pre[p2] = pre[p];
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 0) ans[i] = 2;
    cout << ans[i];
  }
}
