#include <bits/stdc++.h>
using namespace std;
int n, d, b;
int s[100005];
bool can(int k) {
  for (int i = k, ThxDem = (n + 1) / 2 + 1; i < ThxDem; ++i) {
    int e = min(i + 1LL * (i + 1) * d + 1, 1LL * n);
    if (s[e] < b * (i - k + 1)) return false;
  }
  for (int i = n - k - 1; i > (n + 1) / 2; --i) {
    int ss = max(i - 1LL * (n - i) * d, 0LL);
    if (s[n] - s[ss] < b * (n - k - i)) return false;
  }
  return true;
}
int main() {
  scanf("%d%d%d", &n, &d, &b);
  for (int i = 0, ThxDem = n; i < ThxDem; ++i) scanf("%d", s + i + 1);
  for (int i = 0, ThxDem = n; i < ThxDem; ++i) s[i + 1] += s[i];
  int ss = 0, e = (n + 1) / 2 + 1;
  while (e - ss > 1) {
    int m = (ss + e) / 2;
    if (can(m - 1))
      e = m;
    else
      ss = m;
  }
  printf("%d\n", ss);
  return 0;
}
