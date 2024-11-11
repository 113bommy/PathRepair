#include <bits/stdc++.h>
using namespace std;
void Read(int &x) {
  char c;
  bool flag = 0;
  while (c = getchar(), c != EOF && (c < '0' || c > '9') && c != '-')
    ;
  if (c == '-') {
    c = getchar();
    flag = 1;
  }
  x = c - '0';
  while (c = getchar(), c != EOF && c >= '0' && c <= '9') x = x * 10 + c - '0';
  if (flag) x = -x;
}
int a[200010], n;
long long t[200010 * 4], f[200010];
long long x;
long double ans;
void add(int k, int val, int id, int l, int r) {
  if (l == r) {
    t[id] = val;
    return;
  }
  int mid = (l + r) >> 1;
  if (k <= mid)
    add(k, val, id * 2, l, mid);
  else
    add(k, val, id * 2 + 1, mid + 1, r);
  t[id] = t[id * 2] + t[id * 2 + 1];
}
long long ask(int l1, int r1, int id, int l, int r) {
  if (l1 <= l && r <= r1) return t[id];
  int mid = (l + r) >> 1;
  long double res = 0;
  if (l1 <= mid) res += ask(l1, r1, id * 2, l, mid);
  if (r1 > mid) res += ask(l1, r1, id * 2 + 1, mid + 1, r);
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    Read(a[i]);
    f[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    ans += ask(a[i], n, 1, 1, n);
    add(a[i], 1, 1, 1, n);
  }
  ans *= ((long long)n * (n + 1));
  memset(t, 0, sizeof t);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += ask(a[i], n, 1, 1, n);
    ans -= sum;
    add(a[i], f[a[i]] * 2, 1, 1, n);
  }
  for (int i = 1; i <= n; i++)
    ans += ((long long)(n - i + 1) * i * (i - 1) / 2);
  ans /= ((long long)n * (n + 1));
  cout << setprecision(15) << ans << endl;
}
