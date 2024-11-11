#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int n, m;
long long bou, dam, inc;
int mx_h[maxn], s_h[maxn], reg[maxn];
bool sta[maxn];
int pre[maxn];
struct node {
  int t;
  int e;
  int h;
  int tt = -1;
  bool operator<(const node &o) const { return t > o.t; }
  node() {}
  node(int t, int e, int h) : t(t), e(e), h(h) {}
};
priority_queue<node> que;
int main() {
  cin >> n >> m;
  cin >> bou >> inc >> dam;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &mx_h[i], &s_h[i], &reg[i]);
    if (s_h[i] <= dam) {
      sta[i] = 1;
      cnt++;
      if (reg[i]) {
        int nxt_time = 1 + (dam - s_h[i]) / reg[i];
        node new_nd = node(nxt_time, i, dam + 1);
        new_nd.tt = 0;
        if (mx_h[i] > dam) que.push(new_nd);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    int t, e, h;
    scanf("%d %d %d", &t, &e, &h);
    que.push(node(t, e, h));
  }
  long long ans = cnt * bou;
  while (que.size()) {
    node nd = que.top();
    int Time = nd.t;
    ans = max(ans, cnt * (bou + inc * (Time - 1)));
    while (que.size() && que.top().t == Time) {
      nd = que.top();
      if (sta[nd.e] == 1 && nd.h > dam) {
        if (nd.tt == -1 || (pre[nd.e] == nd.tt)) {
          sta[nd.e] = 0;
          cnt--;
        }
      }
      if (nd.h <= dam) {
        if (sta[nd.e] == 0) {
          sta[nd.e] = 1;
          cnt++;
        }
        if (reg[nd.e]) {
          int nxt_time = Time + 1 + (dam - nd.h) / reg[nd.e];
          node new_nd = node(nxt_time, nd.e, dam + 1);
          new_nd.tt = Time;
          if (mx_h[nd.e] > dam) que.push(new_nd);
        }
      }
      if (nd.tt == -1) {
        pre[nd.e] = Time;
      }
      que.pop();
    }
    ans = max(ans, cnt * (bou + inc * Time));
  }
  for (int i = 1; i <= n; i++) {
    if (sta[i] && (reg[i] == 0 || mx_h[i] <= dam) && inc > 0) {
      puts("-1");
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}
