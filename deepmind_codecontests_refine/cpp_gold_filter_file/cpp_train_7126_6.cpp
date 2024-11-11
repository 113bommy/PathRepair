#include <bits/stdc++.h>
using namespace std;
int f[100005], num[100005];
map<int, int> mp;
int findd(int x) { return x != f[x] ? f[x] = findd(f[x]) : f[x]; }
void mergee(int x, int y) {
  int fx = findd(x);
  int fy = findd(y);
  if (fx != fy) f[fx] = fy;
  return;
}
int main() {
  int n, A, B;
  while (~scanf("%d%d%d", &n, &A, &B)) {
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
      scanf("%d", &num[i]);
      mp[num[i]] = i;
    }
    for (int i = 1; i <= n + 2; i++) f[i] = i;
    for (int i = 1; i <= n; i++) {
      if (mp[A - num[i]])
        mergee(i, mp[A - num[i]]);
      else
        mergee(i, n + 2);
      if (mp[B - num[i]])
        mergee(i, mp[B - num[i]]);
      else
        mergee(i, n + 1);
    }
    int x = findd(n + 1);
    int y = findd(n + 2);
    if (x == y)
      puts("NO");
    else {
      puts("YES");
      for (int i = 1; i <= n; i++) {
        if (findd(i) == findd(n + 1))
          printf("0 ");
        else
          printf("1 ");
      }
      printf("\n");
    }
  }
  return 0;
}
