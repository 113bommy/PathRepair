#include <bits/stdc++.h>
using namespace std;
int A[2000], x, y, n, t, tot, d, p;
vector<int> a, b;
void print() {
  printf("? %d", tot);
  for (int i = 1; i <= tot; i++) printf(" %d", A[i]);
  printf("\n");
  fflush(stdout);
}
void work(vector<int> a) {
  int l = 0, r = a.size() - 1, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    tot = 0;
    for (int i = 0; i <= mid; i++) A[++tot] = a[i];
    print();
    scanf("%d", &t);
    if (t == y || t == (x ^ y))
      ans = a[mid], r = mid - 1;
    else
      l = mid + 1;
  }
  printf("! %d %d\n", min(ans, ans ^ d), max(ans, ans ^ d));
}
int main() {
  scanf("%d%d%d", &n, &x, &y);
  int U = (int)log2(n);
  for (int i = 0; i <= U; i++) {
    tot = 0;
    for (int j = 1; j <= n; j++)
      if (j & (1 << i)) A[++tot] = j;
    print();
    scanf("%d", &t);
    if (t == y || t == (x ^ y)) d = d + (1 << i), p = i;
  }
  for (int i = 1; i <= n; i++)
    if (i & (1 << p))
      a.push_back(i);
    else
      b.push_back(i);
  if (a.size() < b.size())
    work(a);
  else
    work(b);
}
