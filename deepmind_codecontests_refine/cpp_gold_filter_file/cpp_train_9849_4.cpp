#include <bits/stdc++.h>
using namespace std;
int Ceil(int n, int k) { return (n + k - 1) / k; }
int main() {
  int n, k, ans, x;
  queue<int> r, q;
  scanf("%d%d", &n, &k);
  ans = min(2 * Ceil(n - 1, k) - 1, 2 * Ceil(n - 2, k));
  printf("%d\n", ans + 1);
  if (ans % 2 == 0) {
    printf("1 2\n");
    r.push(1);
    r.push(2);
  } else {
    r.push(1);
  }
  int m = n - k, s = r.size() + 1;
  x = (ans - 1) / 2;
  while (s <= m) {
    int y = min(s + x - 1, m);
    int root = r.front();
    r.pop();
    printf("%d %d\n", root, s);
    while (s < y) {
      printf("%d %d\n", s, s + 1);
      s++;
    }
    q.push(s);
    s++;
    r.push(root);
  }
  while (r.size()) {
    q.push(r.front());
    r.pop();
  }
  for (; s <= n; s++) {
    printf("%d %d\n", q.front(), s);
    q.push(q.front());
    q.pop();
  }
  return 0;
}
