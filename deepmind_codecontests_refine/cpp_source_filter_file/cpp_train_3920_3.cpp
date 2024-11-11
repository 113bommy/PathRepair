#include <bits/stdc++.h>
using namespace std;
int n, m, t, head[100005];
int getHead(int p) {
  if (head[p] == p) return p;
  return head[p] = getHead(head[p]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) head[i] = i;
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b), --a, --b;
    if (getHead(a) != getHead(b)) {
      head[a] = b;
    } else {
      t *= 2, t++, t %= 1000000009;
    }
    printf("%d\n", t);
  }
}
