#include <bits/stdc++.h>
using namespace std;
const int N = 200050;
int n, k, fa[N];
queue<int> q;
inline bool check(int x) {
  x++;
  int w = 1;
  while (w < x) w <<= 1;
  return (w == x);
}
inline void get(int rt, int l, int r) {
  fa[l] = rt;
  q.push(l);
  for (int i = l + 1; i <= r; i += 2) {
    int now = q.front();
    q.pop();
    fa[i] = fa[i + 1] = now;
    q.push(i);
    q.push(i + 1);
  }
}
inline void T(int a) {
  for (int i = 2; i <= 2 * a; i++) {
    if (i & 1)
      fa[i] = i - 2;
    else
      fa[i] = i - 1;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  if (!(n & 1))
    printf("NO\n");
  else if (k == 0) {
    if (check(n)) {
      printf("YES\n");
      get(0, 1, n);
      for (int i = 1; i <= n; i++) printf("%d ", fa[i]);
      printf("\n");
    } else
      printf("NO\n");
  } else if (k == 1) {
    if (!check(n)) {
      printf("YES\n");
      get(0, 1, n);
      for (int i = 1; i <= n; i++) printf("%d ", fa[i]);
      printf("\n");
    } else
      printf("NO\n");
  } else if (n < 2 * k + 3)
    printf("NO\n");
  else if (n == 9 && k == 2)
    printf("NO\n");
  else {
    printf("YES\n");
    T(k - 1);
    if (check(n - 2 * (k - 1))) {
      get(2 * k - 2 - 1, 2 * k - 1, n - 2);
      fa[n - 1] = fa[n] = 2;
    } else
      get(2 * k - 2 - 1, 2 * k - 1, n);
    for (int i = 1; i <= n; i++) printf("%d ", fa[i]);
    printf("\n");
  }
  return 0;
}
