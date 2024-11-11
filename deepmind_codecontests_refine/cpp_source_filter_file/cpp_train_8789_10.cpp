#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000100];
long long calc(int idx) {
  long long ans = 0;
  int x = -1, y = -1;
  for (int i = 0; i < idx; i += m) {
    ans += (long long)abs(a[i] - a[idx]) * 2;
    x = i;
  }
  for (int i = n - 1; i > idx; i -= m) {
    ans += (long long)abs(a[i] - a[idx]) * 2;
    y = i;
  }
  return ans;
}
long long solve(long long l, long long r) {
  int M, RM, L = l, R = r;
  while (L + 1 < R) {
    M = (L + R) / 2;
    RM = (M + R) / 2;
    if (calc(M) < calc(RM))
      R = RM - 1;
    else
      L = M;
  }
  return L;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int ansid = solve(0, n - 1);
  cout << calc(ansid) << endl;
  return 0;
}
