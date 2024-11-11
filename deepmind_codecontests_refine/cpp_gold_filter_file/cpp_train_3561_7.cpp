#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 1;
int main() {
  int n, num[maxn], top = 0;
  long long t, cnt = 0, ans = 0, last = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &t);
    ans += t / 2;
    if (t % 2 == 1) {
      if (top == 0 || (i - num[top]) % 2 == 0)
        num[++top] = i;
      else
        ans++, num[top--] = 0;
    }
  }
  printf("%lld\n", ans);
}
