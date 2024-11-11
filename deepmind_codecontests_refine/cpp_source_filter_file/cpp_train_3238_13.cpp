#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int a[N];
int cur = 0, cl[N], t[N];
bool del[N];
int main() {
  int n;
  scanf("%d", &n);
  int ng_p = 0, neg = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] < 0) neg ^= 1;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0)
      cl[++cur] = i, del[i] = 1;
    else if (a[i] < 0 && (!ng_p || a[ng_p] < a[i]))
      ng_p = i;
  }
  if (neg) cl[++cur] = ng_p, del[ng_p] = 1;
  for (int i = 1; i < cur; i++) printf("1 %d %d\n", cl[i], cl[i + 1]);
  if (cur < n) printf("2 %d\n", cl[cur]);
  cur = 0;
  for (int i = 1; i <= n; i++)
    if (!del[i]) t[++cur] = i;
  for (int i = 1; i < cur; i++) printf("1 %d %d\n", t[i], t[i + 1]);
  return 0;
}
