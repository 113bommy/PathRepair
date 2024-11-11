#include <bits/stdc++.h>
using namespace std;
void RI() {}
template <typename... T>
void RI(int& head, T&... tail) {
  scanf("%d", &head);
  RI(tail...);
}
long long lasai(int n, int a[]) {
  static int vis[500010], vid, per[500010];
  long long ans = 0;
  for (int i = 0; i < int(n - 2); i++) per[i] = i + 2;
  do {
    vid++;
    long long now = 0;
    for (int ii = 0; ii < int(n - 2); ii++) {
      int i = per[ii];
      vis[i] = vid;
      int l = i, r = i;
      while (vis[l] == vid) l--;
      while (vis[r] == vid) r++;
      now += min(a[l], a[r]);
    }
    ans = max(ans, now);
  } while (next_permutation(per, per + n - 2));
  return ans;
}
int n, a[500010], pre[500010], nxt[500010];
bool vis[500010];
int main() {
  RI(n);
  for (int i = (1); i <= int(n); i++) RI(a[i]);
  for (int i = (0); i <= int(n); i++) nxt[i] = i + 1;
  for (int i = (1); i <= int(n + 1); i++) pre[i] = i - 1;
  priority_queue<pair<int, int> > pq;
  auto val = [&](int i) {
    return a[pre[i]] > a[i] && a[i] < a[nxt[i]] ? 1000000000
                                                : min(a[pre[i]], a[nxt[i]]);
  };
  auto push = [&](int i) { pq.push(make_pair(val(i), i)); };
  for (int i = (2); i <= int(n - 1); i++) push(i);
  long long ans = 0;
  while (!pq.empty()) {
    int i = pq.top().second;
    int v = pq.top().first;
    pq.pop();
    if (vis[i] || val(i) != v) continue;
    vis[i] = 1;
    ans += min(a[pre[i]], a[nxt[i]]);
    nxt[pre[i]] = nxt[i];
    pre[nxt[i]] = pre[i];
    if (pre[i] > 1) push(pre[i]);
    if (nxt[i] < n) push(nxt[i]);
  }
  cout << ans << endl;
  return 0;
}
