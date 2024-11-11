#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e6 + 100;
int n;
long long int a[N];
int max_len[N];
int check(int pos) {
  int ans = 0;
  int sum = 0;
  while (sum < n) {
    ans++;
    sum += max_len[pos];
    pos = (pos + max_len[pos]) % n;
  }
  return ans;
}
int solve(long long int b) {
  long long int total_sum = accumulate(a, a + n, 0ll);
  if (total_sum <= b) return 1;
  for (int i = 0; i < n; i++) a[n + i] = a[i];
  int l = 0;
  int r = 0;
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    while (sum + a[r] <= b) {
      sum += a[r];
      r++;
    }
    max_len[i] = r - l;
    sum -= a[l];
    l++;
  }
  int pos = min_element(max_len, max_len + n) - max_len;
  int ans = n;
  for (int i = 0; i <= max_len[pos]; i++) ans = min(ans, check((pos + i) % n));
  return ans;
}
int main() {
  int q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int i = 0; i < q; i++) {
    long long int b;
    scanf("%lld", &b);
    printf("%d\n", solve(b));
  }
  return 0;
}
