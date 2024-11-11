#include <bits/stdc++.h>
using namespace std;
struct node {
  int num, l;
};
stack<node> s;
int n, a[200001], ans[200001], lenth;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  node p;
  p.num = a[1];
  p.l = 1;
  s.push(p);
  a[++n] = -1;
  for (int i = 2; i <= n; i++) {
    lenth = 0;
    node d;
    d.num = a[i];
    d.l = 1;
    while (!s.empty() && d.num <= s.top().num) {
      lenth += s.top().l;
      ans[lenth] = max(ans[lenth], s.top().num);
      s.pop();
    }
    d.l += lenth;
    s.push(d);
  }
  n--;
  for (int i = n - 1; i >= 1; i--) {
    ans[i] = max(ans[i], ans[i + 1]);
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
