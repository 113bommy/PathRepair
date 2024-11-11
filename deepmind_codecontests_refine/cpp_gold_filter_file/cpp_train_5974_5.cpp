#include <bits/stdc++.h>
using namespace std;
int a[100009], n;
set<int> S;
int f(int x, int k) {
  S.erase(x);
  if (a[n] / x >= k && S.find(x * k) != S.end()) return f(x * k, k) + 1;
  return 1;
}
int main() {
  int i, j, k, s = 0;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    S.insert(a[i]);
  }
  sort(a + 1, a + 1 + n);
  for (i = 1; i <= n; i++)
    if (S.find(a[i]) != S.end()) {
      int t = f(a[i], k);
      s += t / 2 + t % 2;
    }
  printf("%d\n", s);
  return 0;
}
