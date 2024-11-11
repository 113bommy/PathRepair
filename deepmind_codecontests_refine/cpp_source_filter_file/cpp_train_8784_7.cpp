#include <bits/stdc++.h>
using namespace std;
const int N(100010), K(10010);
long long h;
int n, m, k;
vector<int> tre[K];
long long dis[K];
long long a[N];
int c[N], delta[N];
int q[K], p[K];
bool bo[K];
struct Node {
  int i;
  Node() {}
  Node(int _i) { i = _i; }
  bool operator<(const Node &a) const {
    return c[i] < c[a.i] || c[i] == c[a.i] && i < a.i;
  }
};
priority_queue<Node> qu;
int nxt(int x) { return (x + 1) % K; }
void update(long long w, int s) {
  memset(bo, 0, sizeof(bo));
  int t = 0;
  for (int i = int(0); i < int(k); ++i)
    if (dis[i] != -1) {
      bo[i] = true;
      q[t++] = i;
    }
  for (int h = 0; h != t; h = nxt(h)) {
    int y = (q[h] + s) % k;
    long long z = w + (q[h] + s) / k;
    if (dis[y] == -1 || dis[y] > dis[q[h]] + z) {
      dis[y] = dis[q[h]] + z;
      if (!bo[y]) {
        bo[y] = true;
        q[t] = y;
        t = nxt(t);
      }
    }
    bo[q[h]] = false;
  }
}
bool cmp(int x, int y) { return a[x] < a[y]; }
int main() {
  cin >> h >> n >> m >> k;
  for (int i = int(0); i < int(n); ++i) {
    cin >> a[i] >> c[i];
    --a[i];
    tre[int(a[i] % k)].push_back(i);
  }
  for (int i = int(0); i < int(k); ++i) {
    sort(tre[i].begin(), tre[i].end(), cmp);
    p[i] = tre[i].size();
  }
  memset(dis, -1, sizeof(dis));
  dis[0] = 0;
  for (int i = int(0); i < int(k); ++i)
    for (; dis[i] != -1 && p[i] && dis[i] <= a[tre[i][p[i] - 1]] / k;
         qu.push(tre[i][--p[i]]))
      ;
  for (; m; --m) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      long long x;
      cin >> x;
      update(x / k, x % k);
      for (int i = int(0); i < int(k); ++i)
        for (; dis[i] != -1 && p[i] && dis[i] <= a[tre[i][p[i] - 1]] / k;)
          qu.push(tre[i][--p[i]]);
    } else if (cmd == 2) {
      int x, y;
      cin >> x >> y;
      delta[--x] += y;
    } else {
      if (qu.empty()) {
        cout << 0 << endl;
        continue;
      }
      Node no;
      while (true) {
        no = qu.top();
        qu.pop();
        c[no.i] -= delta[no.i];
        if (delta[no.i] == 0) break;
        delta[no.i] = 0;
        qu.push(no);
      }
      cout << c[no.i] << endl;
    }
  }
  return 0;
}
