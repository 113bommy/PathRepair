#include <bits/stdc++.h>
using namespace std;
struct node {
  int val, id;
} a[200050];
int cmp1(node a, node b) { return a.val < b.val; }
struct cmp {
  bool operator()(node a, node b) { return a.val > b.val; }
};
char s[400050];
int main() {
  priority_queue<node, vector<node>, cmp> q;
  while (q.empty() == false) q.pop();
  int n, x, y, i, l;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i].val);
    a[i].id = i;
  }
  scanf("%s", s);
  sort(a + 1, a + 1 + n, cmp1);
  l = strlen(s);
  x = 1;
  y = n;
  for (i = 0; i < l; i++)
    if (s[i] == '0') {
      printf("%d ", a[x].id);
      q.push(a[x]);
      x++;
    } else {
      node jyh = q.top();
      q.pop();
      printf("%d ", jyh.id);
    }
}
