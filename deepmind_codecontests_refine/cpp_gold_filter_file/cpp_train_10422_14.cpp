#include <bits/stdc++.h>
using namespace std;
template <class _T_>
void read(_T_& d) {
  d = 0;
  int f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f *= -1;
  for (; c >= '0' && c <= '9'; c = getchar()) d = d * 10 + c - '0';
  d *= f;
}
int n;
long long l[100005], r[100005];
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) read(l[i]), read(r[i]);
  sort(l + 1, l + n + 1);
  sort(r + 1, r + n + 1);
  long long res = 0;
  for (int i = 1; i <= n; ++i) res += max(r[i], l[i]) + 1;
  cout << res;
  return 0;
}
