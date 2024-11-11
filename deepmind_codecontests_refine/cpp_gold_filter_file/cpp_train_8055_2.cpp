#include <bits/stdc++.h>
using namespace std;
int n, m, K, cnt1, cnt2;
int a[100005], b[100005];
bool cmp(const int &i, const int &j) { return i > j; }
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  sort(a + 1, a + 1 + n, cmp);
  sort(b + 1, b + 1 + m, cmp);
  int j = 1, k = 1;
  for (int i = 1; i <= n; i = j) {
    for (j = i; a[i] == a[j] && j <= n; j++) cnt1++;
    for (; b[k] >= a[i] && k <= m; k++) cnt2++;
    if (cnt1 > cnt2) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
}
