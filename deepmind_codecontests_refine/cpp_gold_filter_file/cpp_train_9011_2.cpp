#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
int main() {
  int n, L, R;
  scanf("%d%d%d", &n, &L, &R);
  R -= L;
  vector<int> a(n), r(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    --x;
    r[x] = i;
  }
  vector<long long> b(n);
  b[r[0]] = 0;
  for (int i = 1; i < n; ++i) {
    int x = r[i - 1], y = r[i];
    b[y] = max(0LL, b[x] - a[x] + 1 + a[y]);
  }
  if (*max_element(b.begin(), b.end()) <= R) {
    for (int i = 0; i < n; ++i) {
      printf("%I64d%c", b[i] + L, " \n"[i == n - 1]);
    }
  } else {
    puts("-1");
  }
  return 0;
}
