#include <bits/stdc++.h>
using namespace std;
int arr[51];
int n, l, r, num;
void solve(long long m) {
  long long tmp = 1L << (n - l - 1);
  if (l == r) {
    arr[l] = num;
  } else if (m <= tmp) {
    arr[l++] = num++;
    solve(m);
  } else {
    arr[r--] = num++;
    solve(m - tmp);
  }
}
int main() {
  int i, j, k;
  long long m;
  scanf("%d %lld", &n, &m);
  l = 1;
  r = n;
  num = 1;
  solve(m);
  for (i = 1; i <= n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
