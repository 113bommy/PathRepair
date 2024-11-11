#include <bits/stdc++.h>
using namespace std;
int n, kq[100010], d[100010];
pair<pair<int, int>, int> a[100010];
void nhap() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].first.first, &a[i].first.second);
    a[i].second = i;
  }
}
void cbi() {
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) d[i] = i;
}
void xuli() {
  for (int i = n; i > 0; i--) {
    while (d[i] + 1 <= n &&
           a[i].first.first + a[i].first.second > a[d[i] + 1].first.first)
      d[i] = max(d[i], d[d[i] + 1]);
    kq[a[i].second] = d[i] + 1;
  }
}
void ghikq() {
  for (int i = 1; i <= n; i++) printf("%d ", kq[i]);
}
int main() {
  nhap();
  cbi();
  xuli();
  ghikq();
  return 0;
}
