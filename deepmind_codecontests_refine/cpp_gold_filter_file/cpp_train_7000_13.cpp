#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
long long sum[N];
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= (n + 1) / 2; i++) scanf("%d", &a[i]);
  int x;
  scanf("%d", &x);
  for (int i = (n + 1) / 2 + 1; i <= n; i++) a[i] = x;
  if (x > 0) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    if (sum > 0) {
      printf("%d\n", n);
    } else
      printf("-1\n");
    return 0;
  }
  for (int i = n; i >= 1; i--) {
    sum[i] = sum[i + 1] + a[i];
  }
  if (*max_element(sum + 1, sum + n + 1) <= 0) {
    printf("-1\n");
    return 0;
  }
  if (sum[1] > 0) {
    printf("%d\n", n);
    return 0;
  }
  priority_queue<int> pq;
  for (int i = 1; i <= n; i++) {
    if (sum[i] > 0 && n - i + 1 > n / 2) {
      pq.push(-(n - i + 1));
    }
  }
  int tot = 0;
  for (int t = 0; pq.size() > 0 && tot < 1000000000; t++) {
    bool flag = true;
    int len = -pq.top();
    pq.pop();
    int x = rand() % 10;
    if (t >= 100 && x == 0) continue;
    for (int i = 1; i <= n - len + 1; i++) {
      tot++;
      if (sum[i] - sum[i + len] <= 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      printf("%d\n", len);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
