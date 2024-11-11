#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long x;
  int y;
} a[300000];
bool cmp(Node x, Node y) { return x.x < y.x; }
long long sum[300000];
int main() {
  int n, k;
  long long ans = 0, temp, ans2 = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i].x), a[i].y = i;
  scanf("%d", &k);
  sort(a, a + n, cmp);
  sum[0] = a[0].x;
  for (int i = 1; i < n; i++) sum[i] += sum[i - 1] + a[i].x;
  for (int i = 1; i < k; i++) ans += a[i].x * i - sum[i - 1];
  temp = ans;
  for (int i = 1; i < n - k + 1; i++) {
    temp += a[i - 1].x * (k - 1) + a[i + k - 1].x * (k - 1) -
            2 * sum[i + k - 2] + 2 * sum[i - 1];
    if (temp < ans) ans = temp, ans2 = i;
  }
  for (int i = ans2; i < ans2 + k; i++) printf("%d ", a[i].y + 1);
  return 0;
}
