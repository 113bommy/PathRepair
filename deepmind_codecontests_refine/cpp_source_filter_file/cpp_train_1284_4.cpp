#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int data[20][3];
bitset<50> mark;
set<pair<long long, long long> > ss;
struct Node {
  pair<long long, long long> g;
  void reset() { g.first = g.second = 0; }
  void set(int x) {
    if (x < 50)
      g.first |= 1ll << x;
    else
      g.second |= 1ll << (x - 50);
  }
  void reset(int x) {
    if (x < 50)
      g.first &= (-1ll) ^ (1ll << x);
    else
      g.second |= (-1ll) ^ (1ll << (x - 50));
  }
  bool test(int x) {
    if (x < 50)
      return (g.first & (1ll << x));
    else
      return (g.second & (1ll << (x - 50)));
  }
  int key;
  friend bool operator<(const Node &a, const Node &b) { return a.key > b.key; }
} tmp;
priority_queue<Node> que;
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 0; i < m; i++)
    scanf("%d%d%d", &data[i][0], &data[i][1], &data[i][2]);
  tmp.reset();
  tmp.key = 0;
  que.push(tmp);
  int ans, tt = 0;
  while (t--) {
    if (que.empty()) {
      ans = -1;
      break;
    }
    tmp = que.top();
    que.pop();
    ans = tmp.key;
    mark.reset();
    for (int i = 0; i < m; i++)
      if (tmp.test(i)) {
        mark.set(data[i][0]), mark.set(data[i][1] + n);
      }
    for (int i = 0; i < m; i++)
      if (!mark.test(data[i][0]) && !mark.test(data[i][1] + n)) {
        tmp.set(i);
        tmp.key += data[i][2];
        if (ss.find(tmp.g) == ss.end()) {
          ss.insert(tmp.g);
          que.push(tmp);
        }
        tmp.key -= data[i][2];
        tmp.reset(i);
      }
  }
  printf("%d\n", ans);
  return 0;
}
