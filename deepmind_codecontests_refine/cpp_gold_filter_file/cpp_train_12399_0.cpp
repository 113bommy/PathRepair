#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
long long a[maxn], b[maxn];
bool cmp(const long long &a, const long long &b) { return a > b; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &b[i]);
  }
  sort(a + 1, a + n + 1, cmp);
  sort(b + 1, b + n + 1, cmp);
  long long asum = 0, bsum = 0;
  int i = 1, j = 1;
  bool p = true;
  while (i <= n || j <= n) {
    if (p == true) {
      if ((a[i] > b[j] || j > n) && i <= n) {
        asum += a[i];
        i++;
      } else {
        j++;
      }
    } else {
      if ((b[j] > a[i] || i > n) && j <= n) {
        bsum += b[j];
        j++;
      } else {
        i++;
      }
    }
    p = !p;
  }
  printf("%I64d\n", asum - bsum);
  return 0;
}
