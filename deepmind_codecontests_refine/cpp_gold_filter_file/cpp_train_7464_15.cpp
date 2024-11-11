#include <bits/stdc++.h>
using namespace std;
int a[200001];
int b[600001];
int n, L;
bool chk(int d) {
  if (d * 2 >= L) return true;
  int l = 0, r = 3 * n - 1;
  while (b[l] < a[0] - d) l++;
  while (b[r] > a[0] + d) r--;
  for (int i = 1; i < n; i++) {
    l++;
    r++;
    while (b[l] < a[i] - d) l++;
    if (b[r] > a[i] + d) r--;
  }
  return l <= r;
}
void Init() {
  scanf("%d%d", &n, &L);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", b + n + i);
}
void Solve() {
  for (int i = 0; i < n; i++) {
    b[i] = b[i + n] - L;
    b[i + 2 * n] = b[i + n] + L;
  }
  sort(a, a + n);
  sort(b, b + 3 * n);
  int left = 0, right = L / 2 + 1;
  while (left < right) {
    int m = (left + right) >> 1;
    if (chk(m))
      right = m;
    else
      left = m + 1;
  }
  printf("%d\n", left);
}
int main() {
  Init();
  Solve();
  return 0;
}
