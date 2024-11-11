#include <bits/stdc++.h>
const int N = 1e5 + 10;
long long ri() {
  char c = getchar();
  long long x = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c;
  return x * f;
}
std::vector<long long> b[68];
long long ans[N], bin[68];
int n;
int main() {
  n = ri();
  bin[0] = 1;
  for (int i = 1; i <= 59; ++i) bin[i] = bin[i - 1] << 1;
  for (int i = 1; i <= n; ++i) {
    long long x = ri();
    for (int j = 59; ~j; --j)
      if (x & bin[j]) {
        b[j].push_back(x);
        break;
      }
  }
  long long x = 0;
  for (int i = 1; i <= n; ++i) {
    bool flag = false;
    for (int j = 0; j < 59; ++j)
      if ((~x & bin[j]) && b[j].size()) {
        ans[i] = b[j][b[j].size() - 1];
        x ^= ans[i];
        b[j].pop_back();
        flag = true;
        break;
      }
    if (!flag) return puts("No"), 0;
  }
  puts("Yes");
  for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
  puts("");
  return 0;
}
