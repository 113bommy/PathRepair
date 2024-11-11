#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000;
struct node {
  long long k, data;
  node() {}
  node(long long _k, long long _data) : k(_k), data(_data) {}
  bool operator<(const node& a) const { return data > a.data; }
};
priority_queue<node> Q;
const int N = 111111;
int f[111111];
long long len[111111], sz[111111];
bool bi[111111];
int s(int k) {
  if (f[k] == k) return k;
  return (f[k] = s(f[k]));
}
int n, m, p, q;
vector<pair<int, int> > ans;
int main() {
  while (scanf("%d %d %d %d", &n, &m, &p, &q) == 4) {
    for (int i = 1; i <= n; ++i) {
      f[i] = i;
      len[i] = 0;
      sz[i] = 1;
    }
    int p1, p2, p3, can1 = 0, can2 = 0;
    for (int i = 0; i < m; ++i) {
      scanf("%d %d %d", &p1, &p2, &p3);
      p1 = s(p1);
      p2 = s(p2);
      if (p1 == p2) {
        len[p1] += p3;
      } else {
        len[p1] += len[p2] + p3;
        sz[p1] += sz[p2];
        f[p2] = p1;
        can1 = p1;
        can2 = p2;
      }
    }
    while (!Q.empty()) Q.pop();
    memset(bi, true, sizeof(bi));
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
      int k = s(i);
      if (bi[k]) {
        bi[k] = false;
        Q.push(node(k, len[k]));
        tot++;
      }
    }
    if (tot < q || tot - p > q) {
      puts("NO");
      continue;
    }
    bool flag = true;
    ans.clear();
    for (int i = 0; flag && i < p; ++i) {
      node t1 = Q.top();
      Q.pop();
      if (tot == q) {
        if (can1) {
          ans.push_back(make_pair(can1, can2));
          Q.push(t1);
        } else {
          flag = false;
        }
      } else {
        node t2 = Q.top();
        Q.pop();
        long long ret = min(inf, len[t1.k] + len[t2.k]);
        ans.push_back(make_pair(t1.k, t2.k));
        len[t1.k] += len[t2.k] + ret;
        sz[t1.k] += sz[t2.k];
        f[t2.k] = t1.k;
        can1 = t1.k;
        can2 = t2.k;
        Q.push(node(t1.k, len[t1.k]));
        --tot;
      }
    }
    if (!flag)
      puts("NO");
    else {
      puts("YES");
      for (int i = 0; i < p; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}
