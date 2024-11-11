#include <bits/stdc++.h>
using namespace std;
const int N = 303;
long long T;
int n, tot, num, p[25];
struct Node {
  int x1, y1, x2, y2;
} ans[N];
inline void add(int n, int x) {
  if (x == 0) {
    ans[num++] = (Node){n + 1, n - 1, n + 1, n};
    ans[num++] = (Node){n + 2, n - 1, n + 2, n};
    ans[num++] = (Node){n - 1, n + 1, n, n + 1};
    ans[num++] = (Node){n - 1, n + 2, n, n + 2};
  } else if (x == 1) {
    ans[num++] = (Node){n + 1, n - 1, n + 1, n};
    ans[num++] = (Node){n - 1, n + 1, n, n + 1};
    ans[num++] = (Node){n - 1, n + 2, n, n + 2};
  } else if (x == 2) {
    ans[num++] = (Node){n + 1, n - 1, n + 1, n};
    ans[num++] = (Node){n - 1, n + 1, n, n + 1};
  } else if (x == 3) {
    ans[num++] = (Node){n + 2, n - 1, n + 2, n};
    ans[num++] = (Node){n - 1, n + 1, n, n + 1};
    ans[num++] = (Node){n - 1, n + 2, n, n + 2};
  } else if (x == 4) {
    ans[num++] = (Node){n - 1, n + 1, n, n + 1};
    ans[num++] = (Node){n - 1, n + 2, n, n + 2};
  } else if (x == 5) {
    ans[num++] = (Node){n - 1, n + 1, n, n + 1};
  }
}
int main() {
  scanf("%lld", &T);
  while (T) p[++tot] = T % 6ll, T /= 6ll;
  ans[num++] = (Node){1, 2, 2, 2};
  ans[num++] = (Node){2, 1, 2, 2};
  n = 2;
  while (tot) {
    add(n, p[tot--]);
    n += 2;
    if (tot) {
      ans[num++] = (Node){n, n - 2, n + 1, n - 2};
      ans[num++] = (Node){n, n - 1, n + 1, n - 1};
      ans[num++] = (Node){n + 1, n - 3, n + 2, n - 3};
      ans[num++] = (Node){n + 1, n - 2, n + 2, n - 2};
      ans[num++] = (Node){n - 2, n, n - 2, n + 1};
      ans[num++] = (Node){n - 1, n, n - 1, n + 1};
      ans[num++] = (Node){n - 3, n + 1, n - 3, n + 2};
      ans[num++] = (Node){n - 2, n + 1, n - 2, n + 2};
    }
  }
  printf("%d %d\n%d\n", n, n, num);
  for (register int i = 0; i < num; i++)
    printf("%d %d %d %d\n", ans[i].x1, ans[i].y1, ans[i].x2, ans[i].y2);
}
