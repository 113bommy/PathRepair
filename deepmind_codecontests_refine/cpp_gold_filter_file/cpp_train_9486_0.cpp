#include <bits/stdc++.h>
using namespace std;
int N, M, K;
struct s {
  int n, idx;
  long long c;
  s(int n, long long c, int idx) : n(n), c(c), idx(idx){};
};
struct cmp {
  bool operator()(s o1, s o2) { return o1.c > o2.c; }
};
vector<s> v[300001];
long long d[300001];
bool idx[300001];
vector<int> ans;
int main() {
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 1; i <= N; ++i) d[i] = 0x7fffffffffffffff;
  int n1, n2;
  long long c;
  for (int i = 1; i <= M; ++i) {
    scanf("%d %d %lld", &n1, &n2, &c);
    v[n1].push_back(s(n2, c, i));
    v[n2].push_back(s(n1, c, i));
  }
  priority_queue<s, vector<s>, cmp> pq;
  pq.push(s(1, 0LL, 0));
  d[1] = 0LL;
  int k = K + 1;
  while (!pq.empty()) {
    s now = pq.top();
    pq.pop();
    if (d[now.n] != now.c) continue;
    idx[now.idx] = true;
    ans.push_back(now.idx);
    k--;
    if (!k) break;
    for (s next : v[now.n]) {
      if (d[next.n] > now.c + next.c) {
        d[next.n] = now.c + next.c;
        pq.push(s(next.n, now.c + next.c, next.idx));
      }
    }
  }
  printf("%d\n", ans.size() - 1);
  for (int i = 1; i < ans.size(); ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
