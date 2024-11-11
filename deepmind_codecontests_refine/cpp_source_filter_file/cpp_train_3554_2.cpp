#include <bits/stdc++.h>
using namespace std;
int n, k, T, st, ans = 0;
int A[1005];
int flag[1005];
struct node {
  int T;
  int index;
  friend bool operator<(node a, node b) { return a.T > b.T; }
};
priority_queue<node> q;
void op(int st, int T) {
  node a;
  if (st <= n) {
    a.T = T + A[st];
    a.index = st;
    q.push(a);
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= k; i++) {
    node a;
    a.T = A[i], a.index = i;
    q.push(a);
  }
  st = k;
  for (int i = 1; i <= n - 1; i++) {
    node a = q.top();
    q.pop();
    T = a.T;
    int sys = (int)(100 * i / float(n) + 0.50);
    op(++st, T);
    vector<node> c;
    int tm = q.top().T;
    while (!q.empty()) {
      a = q.top();
      c.push_back(a);
      q.pop();
    }
    for (auto p : c) {
      a = p;
      int now = A[a.index] - (a.T - T);
      if (now < sys && sys < A[a.index] && T + sys - now <= tm)
        flag[a.index] = 1;
      q.push(p);
    }
    c.clear();
  }
  for (int i = 1; i <= n; i++) ans += flag[i];
  cout << ans << endl;
}
