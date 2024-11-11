#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
int n, a[106];
int vis[106];
int x, cot;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int main() {
  cot = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      x = a[i];
      vis[i] = 1;
      cot++;
      for (int j = i + 1; j < n; j++) {
        if (!vis[j] && gcd(a[j], x) != 1) {
          vis[j] = 1;
        }
      }
    }
  }
  printf("%d\n", cot);
  return 0;
}
