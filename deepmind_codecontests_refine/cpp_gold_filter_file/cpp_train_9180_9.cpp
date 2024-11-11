#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
char s[600005];
int sum[300005];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    s[i + n] = s[i];
  }
  sum[0] = 0;
  int pos = 0, minn = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
    if (sum[i] < minn) {
      minn = sum[i];
      pos = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (s[i + pos] == '(' ? 1 : -1);
  }
  if (sum[n] != 0) {
    printf("0\n1 1\n");
    return 0;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (sum[i] == 0) {
      ans++;
    }
  }
  int maxans = 0, p1 = 1, p2 = 1;
  for (int i = 1; i <= n; i++) {
    int j = i, n1 = 0, n2 = 0, maxn = 0, t1 = 1, t2 = 1, pre = i;
    while (j <= n && sum[j] != 0) {
      j++;
    }
    for (int k = i; k <= j; k++) {
      if (sum[k] == 1) {
        if (maxn < n2) {
          maxn = n2;
          t1 = pre + 1;
          t2 = k;
        }
        n2 = 0;
        n1++;
        pre = k;
      } else if (sum[k] == 2) {
        n2++;
      }
    }
    if (maxn < n2) {
      maxn = n2;
      t1 = pre + 1;
      t2 = j;
    }
    if (maxans < maxn + ans) {
      maxans = maxn + ans;
      p1 = t1;
      p2 = t2;
    }
    if (maxans < n1) {
      maxans = n1, p1 = i, p2 = j;
    }
    i = j;
  }
  printf("%d\n%d %d\n", maxans, (p1 + pos - 1) % n + 1, (p2 + pos - 1) % n + 1);
  return 0;
}
