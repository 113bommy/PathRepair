#include <bits/stdc++.h>
const double pi = acos(-1.0);
const int INF = 0x7FFFFFFF;
using namespace std;
const int maxn = 10010;
int p[maxn];
bool sorting(int l, int r, int index) {
  int low = 0;
  for (int i = l - 1; i < r; i++)
    if (p[i] < p[index - 1]) low++;
  if (l + low == index) return 1;
  return 0;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", p + i);
  for (int i = 0; i < m; i++) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    if (sorting(l, r, x))
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
