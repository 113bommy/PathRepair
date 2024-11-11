#include <bits/stdc++.h>
using namespace std;
struct Node {
  int id;
  int num;
  friend bool operator<(Node a, Node b) {
    if (a.num != b.num)
      return a.num < b.num;
    else
      return a.id < b.id;
  }
} temp[400010];
priority_queue<Node> que;
int n, s;
int ans_x[400010], ans_y[400010];
int main() {
  int i, x, flag = 0, k, sum = 0;
  Node node, head, tail;
  scanf("%d%d", &n, &s);
  for (i = 1; i <= n; i++) {
    node.id = i;
    scanf("%d", &x);
    node.num = x;
    if (x) que.push(node);
  }
  while (!que.empty()) {
    head = que.top();
    que.pop();
    if (head.num > que.size()) {
      flag = 1;
      break;
    }
    k = 0;
    for (i = 0; i < head.num; i++) {
      tail = que.top();
      que.pop();
      tail.num--;
      temp[k++] = tail;
      ans_x[sum] = head.id;
      ans_y[sum] = tail.id;
      sum++;
    }
    for (i = 0; i < k; i++) {
      if (temp[i].num > 0) {
        que.push(temp[i]);
      }
    }
  }
  if (flag)
    printf("No\n");
  else {
    printf("Yes\n");
    printf("%d\n", sum);
    for (i = 0; i < sum; i++) printf("%d %d\n", ans_x[i], ans_y[i]);
  }
  return 0;
}
