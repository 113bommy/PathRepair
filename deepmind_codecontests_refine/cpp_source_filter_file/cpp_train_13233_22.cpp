#include <bits/stdc++.h>
using namespace std;
int n, k = 0, b[900005];
int sum;
struct note {
  int num;
  int x;
} a[900005];
int cmp(note m, note n) { return m.x < n.x; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].x);
    a[i].num = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int j = 1; j < n; j++) sum += a[j].x;
  for (int i = 1; i < n; i++) {
    sum -= a[i].x;
    if (sum == a[n].x) {
      b[k] = a[i].num;
      k++;
    }
    sum += a[i].x;
  }
  sum -= a[n - 1].x;
  if (sum == a[n - 1].x) {
    b[k] = a[n].num;
    k++;
  }
  printf("%d\n", k);
  for (int i = 0; i < k; i++) cout << b[i] << ' ';
  return 0;
}
