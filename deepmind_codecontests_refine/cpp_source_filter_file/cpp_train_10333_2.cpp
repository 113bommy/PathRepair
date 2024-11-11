#include <bits/stdc++.h>
using namespace std;
int read();
long long readll();
int n, k, mx, f[1009];
bool on[1009];
vector<int> q;
bool check() {
  int i, tmp = 0;
  for (i = 1; i <= n; i++) tmp += on[i];
  if (tmp >= mx) {
    puts("0");
    return 0;
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  if (n <= 3) {
    puts("0");
    return 0;
  }
  int i, x;
  k = 2;
  for (i = 3; i < n - 1; i++)
    if (n / i * (i - 1) + max(0, n % i - 1) - (i - 1) >
        n / k * (k - 1) + max(0, n % i - 1) - (k - 1))
      k = i;
  mx = n / k * (k - 1) + max(0, n % i - 1) - (k - 1);
  for (i = 1; i <= n; i++) f[i] = (i - 1) % k + 1;
  f[n] = k;
  while (check()) {
    q.clear();
    for (i = 1; i <= n; i++)
      if (!on[i] && f[i] < k) {
        q.push_back(i);
        on[i] = 1;
        if (q.size() == k) break;
      }
    printf("%d", q.size());
    for (int p : q) printf(" %d", p);
    puts("");
    fflush(stdout);
    scanf("%d", &x);
    for (i = x; i < x + k; i++) on[(i - 1) % n + 1] = 0;
  }
  return 0;
}
int read() {
  int x = 0;
  char ch = getchar();
  bool flag = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return flag ? -x : x;
}
long long readll() {
  long long x = 0;
  char ch = getchar();
  bool flag = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return flag ? -x : x;
}
