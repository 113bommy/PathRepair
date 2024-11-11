#include <bits/stdc++.h>
using namespace std;
struct Node {
  int op, val;
};
Node num[(2000000 + 10)];
bool cmp(Node a, Node b) {
  if (a.val != b.val)
    return a.val < b.val;
  else
    return a.op > b.op;
}
int ans[(2000000 + 10)];
int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  int top = 0;
  for (int i = 0; i < n; i++) {
    int s, t;
    scanf("%d", &s);
    scanf("%d", &t);
    num[top].val = s;
    num[top++].op = 1;
    num[top].val = t;
    num[top++].op = 0;
  }
  sort(num, num + top, cmp);
  int cnt = 0;
  int have = 0;
  for (int i = 0; i < top; i++) {
    if (num[i].op) {
      have++;
      if (have == k) ans[cnt++] = num[i].val;
    } else {
      if (have == k) ans[cnt++] = num[i].val;
      have--;
    }
  }
  printf("%d\n", (cnt / 2));
  for (int i = 0; i < cnt; i += 2) printf("%d %d\n", ans[i], ans[i + 1]);
  return 0;
}
