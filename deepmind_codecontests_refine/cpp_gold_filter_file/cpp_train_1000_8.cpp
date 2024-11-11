#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
long long m, k;
int a[maxn];
pair<int, int> stk[maxn];
int top;
int main() {
  scanf("%d%lld%lld", &n, &k, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  int lft = n;
  for (int i = 1; i <= n; i++) {
    if (!top || a[i] != stk[top].first)
      stk[++top] = make_pair(a[i], 1);
    else {
      stk[top].second++;
      if (stk[top].second == k) {
        --top;
        lft -= k;
      }
    }
  }
  int p = 0, l = 1, r = top;
  while (p + 1 <= r && stk[p + 1].first == stk[r - p].first &&
         stk[p + 1].second + stk[r - p].second == k)
    ++p;
  if (p == r) {
    if (m % 2 == 0)
      puts("0");
    else {
      printf("%d\n", lft);
    }
    return 0;
  }
  if (r % 2 == 0 || (r % 2 == 1 && p != r / 2)) {
    long long sum = 0, c = 0;
    for (int i = 1; i <= p; i++) sum += stk[i].second + stk[r - i + 1].second;
    for (int i = p + 1; i <= r - p; i++) c += stk[i].second;
    sum += c * m;
    sum -= (stk[p + 1].first == stk[r - p].first
                ? (m - 1) * ((stk[p + 1].second + stk[r - p].second) / k * k)
                : 0);
    printf("%lld\n", sum);
  } else {
    if (p == r / 2) {
      if (m * stk[p + 1].second % k == 0) {
        puts("0");
      } else {
        long long sum = 0;
        for (int i = 1; i <= p; i++)
          sum += stk[i].second + stk[r - i + 1].second;
        sum += m * stk[p + 1].second % k;
        printf("%lld\n", sum);
      }
    }
  }
  return 0;
}
