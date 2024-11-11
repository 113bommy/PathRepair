#include <bits/stdc++.h>
using namespace std;
int n, r;
long long k;
long long sum[500001];
long long cf[500001];
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
}
bool check(long long x) {
  long long rest = k, need;
  long long add = 0;
  memset(cf, 0, sizeof(cf));
  for (int i = 1; i <= n; ++i) {
    add += cf[i];
    if (sum[i] + add < x) {
      need = x - sum[i] - add;
      rest -= need;
      if (rest < 0) return false;
      cf[i + 1] += need;
      if (i + 2 * r < n) cf[i + 2 * r + 1] -= need;
    }
  }
  return true;
}
int main() {
  read(n);
  read(r);
  read(k);
  int x;
  for (int i = 1; i <= n; ++i) {
    read(x);
    sum[max(0, i - r)] += x;
    if (i + r < n) sum[i + r + 1] -= x;
  }
  for (int i = 1; i <= n; ++i) sum[i] += sum[i - 1];
  long long l = 0, r = 2e18, mid, ans = 0;
  while (l <= r) {
    mid = l + r >> 1;
    if (check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  cout << ans;
}
