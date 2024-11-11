#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct node {
  int x, num;
  node() {}
  node(int _x, int _num) { x = _x, num = _num; }
  bool operator<(const node& b) const { return num > b.num; }
};
int val[maxn], num[maxn];
int ans[maxn][3];
map<int, int> mp;
priority_queue<node> pq;
int main() {
  int dif = 0;
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &val[i]);
    if (!mp[val[i]]) {
      mp[val[i]] = 1;
      num[dif++] = val[i];
    } else
      mp[val[i]]++;
  }
  for (int i = 0; i < dif; i++) {
    pq.push(node(num[i], mp[num[i]]));
  }
  int now = 0, j = 0;
  while (pq.size() >= 3) {
    node tmp1 = pq.top();
    pq.pop();
    node tmp2 = pq.top();
    pq.pop();
    node tmp3 = pq.top();
    pq.pop();
    ans[now][0] = tmp1.x, tmp1.num--;
    ans[now][1] = tmp2.x, tmp2.num--;
    ans[now][2] = tmp3.x, tmp3.num--;
    now++;
    if (tmp1.num) pq.push(tmp1);
    if (tmp2.num) pq.push(tmp2);
    if (tmp3.num) pq.push(tmp3);
  }
  printf("%d\n", now);
  for (int i = 0; i < now; i++) {
    int a = ans[i][0], b = ans[i][1], c = ans[i][2];
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    printf("%d %d %d\n", c, b, a);
  }
  return 0;
}
