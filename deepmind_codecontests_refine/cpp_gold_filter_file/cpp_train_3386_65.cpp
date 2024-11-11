#include <bits/stdc++.h>
using namespace std;
long long a[200000 + 10], s[200000 + 10];
struct line {
  long long k, b;
  line(long long k = 0, long long b = 0) : k(k), b(b) {}
  long long f(long long x) { return k * x + b; }
} L[200000 + 10];
int sta[200000 + 10], p;
int judge(line a, line b, line c) {
  return (b.b - a.b) * (b.k - c.k) >= (c.b - b.b) * (a.k - b.k);
}
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    ans += a[i] * i;
    s[i] = s[i - 1] + a[i];
  }
  long long d = 0;
  for (int i = n; i; i--) {
    L[i] = line(i, -s[i]);
    while (p > 1 && !judge(L[sta[p - 1]], L[sta[p]], L[i])) p--;
    sta[++p] = i;
    int l = 1, r = p;
    while (l < r) {
      int m = l + r >> 1;
      if (L[sta[m]].f(a[i]) >= L[sta[m + 1]].f(a[i]))
        r = m;
      else
        l = m + 1;
    }
    int k = sta[l];
    d = max(d, s[i] - s[k] + a[i] * (k - i));
  }
  p = 0;
  for (int i = 1; i <= n; i++) {
    L[i] = line(i, -s[i - 1]);
    while (p > 1 && !judge(L[i], L[sta[p]], L[sta[p - 1]])) p--;
    sta[++p] = i;
    int l = 1, r = p;
    while (l < r) {
      int m = l + r >> 1;
      if (L[sta[m]].f(a[i]) <= L[sta[m + 1]].f(a[i]))
        l = m + 1;
      else
        r = m;
    }
    int k = sta[l];
    d = max(d, s[i - 1] - s[k - 1] - a[i] * (i - k));
  }
  cout << ans + d << endl;
  return 0;
}
