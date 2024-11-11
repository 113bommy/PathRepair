#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
struct _two {
  int a, b;
} a[N];
int n;
int ans[N], need[N], last[N];
void Init() {
  scanf("%d", &n);
  a[0].b = n + 1;
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].a, &a[i].b);
}
bool check(int x) {
  memset(need, 0, sizeof(need));
  need[n] = n;
  for (int i = 1; i <= n; i++) last[i] = n;
  for (int i = 1; i <= n; i++) {
    int pos = n;
    for (int j = i; j <= n; j++) {
      if (need[j] > j) return 0;
      if (need[j] == j) {
        pos = j;
        break;
      }
    }
    int Min = 0;
    for (int j = 1; j <= n; j++)
      if (last[j] <= pos && a[j].b < a[Min].b) Min = j;
    ans[i] = Min;
    for (int j = i; j <= last[Min] - 1; j++) need[j]++;
    last[Min] = n + 1;
    for (int j = 1; j <= n; j++)
      if (a[j].a <= a[Min].b && a[Min].a <= a[j].b && last[j] <= n) {
        if (last[j] > i + x) {
          for (int k = i + x; k <= last[j] - 1; k++) need[k]++;
          last[j] = i + x;
        }
      }
  }
  return 1;
}
void Work() {
  int left = 0, right = n - 1;
  while (left < right) {
    int mid = left + right >> 1;
    if (check(mid))
      right = mid;
    else
      left = mid + 1;
  }
  check(left);
  for (int i = 1; i <= n; i++) {
    if (i != 1) putchar(' ');
    printf("%d", ans[i]);
  }
  puts("");
}
int main() {
  Init();
  Work();
  return 0;
}
