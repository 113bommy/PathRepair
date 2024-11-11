#include <bits/stdc++.h>
using namespace std;
int a[400005], x[400005], S[400005];
int A[400005];
void Manachers(int n) {
  int r = 0, p = 1;
  for (int i = 2; i <= n * 2 + 1; i++) {
    if (i <= r)
      A[i] = min(A[2 * p - i], r - i);
    else
      A[i] = 0;
    while (i - A[i] - 1 > 0 && i + A[i] + 1 <= 400005 &&
           S[i - A[i] - 1] == S[i + A[i] + 1])
      A[i]++;
    if (r < i + A[i]) r = i + A[i], p = i;
  }
}
bool isGood(int l, int r) {
  if (l >= r) {
    return true;
  }
  int mid = l + r;
  if (mid + A[mid] - 1 >= r && mid - A[mid] + 1 <= l) {
    return true;
  } else {
    return false;
  }
}
int ret[400005];
void solve() {
  int n, m;
  scanf("%d %d ", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d ", &a[i]);
    x[i] = a[i] - a[i - 1];
    S[i * 2] = x[i];
    S[i * 2 - 1] = -1;
  }
  S[n * 2 + 1] = -1;
  int num = 0;
  Manachers(n);
  if (isGood(2, n)) {
    ret[num++] = (a[1] + a[n]) % m;
  }
  for (int i = 1; i < n; ++i) {
    if ((a[1] + a[i]) % m == (a[i + 1] + a[n]) % m && isGood(2, i) &&
        isGood(i + 2, n)) {
      ret[num++] = (a[1] + a[i]) % m;
    }
  }
  printf("%d\n", num);
  if (num > 0) {
    sort(ret, ret + num);
  }
  for (int i = 0; i < num; ++i) {
    printf("%d ", ret[i]);
  }
  putchar('\n');
}
int main() {
  solve();
  return 0;
}
