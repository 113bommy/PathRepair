#include <bits/stdc++.h>
using namespace std;
const int oo = 0x7f7f7f7f;
const int maxn = 2000 + 10;
int a[maxn];
int main() {
  int n, b;
  scanf("%d%d", &n, &b);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int ans = b;
  for (int i = 1; i < n; i++) {
    int tmp = oo;
    for (int j = 0; j < i; j++) {
      tmp = tmp < a[j] ? tmp : a[j];
    }
    int nn = b / tmp;
    int less = b % tmp;
    int t = less + nn * a[i];
    ans = ans > t ? ans : t;
  }
  printf("%d\n", ans);
}
