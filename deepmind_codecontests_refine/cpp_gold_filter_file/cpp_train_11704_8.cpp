#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n, k;
struct Node {
  int num;
  int pos;
} node[MAXN];
set<int> sPos, sVal;
int c[MAXN];
long long ans = 0;
bool cmp(Node aa, Node bb) { return aa.num < bb.num; }
int lowbit(int x) { return x & -x; }
void add(int x, int v) {
  for (; x <= n; x += lowbit(x)) c[x] += v;
}
int sum(int x) {
  int s = 0;
  for (; x; x -= lowbit(x)) s += c[x];
  return s;
}
void solve() {
  sort(node + 1, node + n + 1, cmp);
  sPos.insert(0);
  sPos.insert(n + 1);
  for (int i = 1; i <= n; i++) {
    if (sVal.find(node[i].num) != sVal.end()) {
      sPos.insert(node[i].pos);
    } else {
      set<int>::iterator it;
      it = sPos.lower_bound(node[i].pos);
      int e = *it;
      it--;
      int s = *it;
      int cnt = sum(e - 1) - sum(s);
      ans += e - s - 1 - cnt;
      add(node[i].pos, 1);
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &node[i].num);
    node[i].pos = i;
  }
  for (int i = 0; i < k; i++) {
    int b;
    scanf("%d", &b);
    sVal.insert(b);
  }
  solve();
  printf("%I64d\n", ans);
  return 0;
}
