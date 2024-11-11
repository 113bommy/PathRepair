#include <bits/stdc++.h>
using namespace std;
int a, b;
vector<int> p, q;
int main() {
  scanf("%d %d", &a, &b);
  int x = -1, y = 1;
  if (a == 0) {
    printf("%d\n", 0);
  } else {
    while (a >= y) a -= y, p.push_back(y), y++;
    if (a > 0) {
      x = y - a;
      p.push_back(y++);
    }
    printf("%d\n", int(p.size()) + (x != -1 ? 1 : 0));
    for (size_t i = 0; i < p.size(); i++)
      if (p[i] != x) printf("%d ", p[i]);
    printf("\n");
  }
  if (x != -1 && b >= x) b -= x, q.push_back(x);
  while (b >= y) b -= y, q.push_back(y), y++;
  printf("%d\n", int(q.size()));
  for (size_t i = 0; i < q.size(); i++) printf("%d ", q[i]);
  printf("\n");
  return 0;
}
