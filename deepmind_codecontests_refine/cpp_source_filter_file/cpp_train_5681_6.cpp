#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, num[N], lim;
int ans[N * N][2], tmp;
struct node {
  int id, val;
  bool operator<(const node &tmp) const { return val < tmp.val; }
};
priority_queue<node> que;
void solve(int p) {
  int cnt = 0;
  while (!que.empty()) que.pop();
  for (int i = 1; i <= n; i++)
    if (num[i] > p) que.push((node){i, num[i] - p});
  while (que.size() >= 2) {
    cnt++;
    node t1 = que.top();
    que.pop();
    node t2 = que.top();
    que.pop();
    t1.val--, t2.val--;
    if (t1.val > 0) que.push(t1);
    if (t2.val > 0) que.push(t2);
    ans[cnt][0] = t1.id;
    ans[cnt][1] = t2.id;
    if (que.size() == 1) tmp = que.top().id;
  }
  printf("%d\n%d\n", p, cnt);
  for (int i = 1; i < cnt; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == ans[i][0] || j == ans[i][1])
        printf("1");
      else
        printf("0");
    }
    puts("");
  }
  if (cnt == 0) exit(0);
  for (int j = 1; j <= n; j++) {
    if (j == ans[cnt][0] || j == ans[cnt][1] || j == tmp)
      printf("1");
    else
      printf("0");
  }
  puts("");
  exit(0);
}
int main() {
  scanf("%d", &n);
  lim = 100;
  for (int i = 1; i <= n; i++) {
    scanf("%d", num + i);
    lim = min(lim, num[i]);
  }
  for (int i = lim; i >= 1; i--) {
    int sum = 0, mx = 0;
    for (int j = 1; j <= n; j++)
      if (num[j] > i) sum += num[j] - i, mx = max(mx, num[j] - i);
    int oth = sum - mx;
    if (sum % 2 == 1) {
      if (oth - 1 < mx)
        continue;
      else
        solve(i);
    } else {
      if (oth < mx)
        continue;
      else
        solve(i);
    }
  }
  int cnt = 0;
  while (!que.empty()) que.pop();
  for (int i = 1; i <= n; i++) que.push((node){i, num[i]});
  while (que.size() >= 2) {
    cnt++;
    node t1 = que.top();
    que.pop();
    node t2 = que.top();
    que.pop();
    t1.val--, t2.val--;
    if (t1.val > 0) que.push(t1);
    if (t2.val > 0) que.push(t2);
    ans[cnt][0] = t1.id;
    ans[cnt][1] = t2.id;
  }
  if (que.size() == 1) {
    cnt++;
    node t1 = que.top();
    que.pop();
    t1.val--;
    if (t1.val > 0) que.push(t1);
    ans[cnt][0] = t1.id;
    if (t1.id != 1)
      ans[cnt][1] = 1;
    else
      ans[cnt][1] = 2;
  }
  printf("%d\n%d\n", 0, cnt);
  for (int i = 1; i <= cnt; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == ans[i][0] || j == ans[i][1])
        printf("1");
      else
        printf("0");
    }
    puts("");
  }
  return 0;
}
