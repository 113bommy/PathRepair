#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, p, x[N], c[N];
long long t, a[N], b[N];
int main() {
  scanf("%d%lld", &n, &t);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%lld", &a[i]);
  for (int i = (int)(1); i <= (int)(n); i++) {
    scanf("%d", &x[i]);
    if (x[i] < i) return puts("No"), 0;
    c[i]++;
    c[x[i]]--;
  }
  for (int i = (int)(1); i <= (int)(n); i++)
    if (p += c[i])
      b[i] = a[i + 1] + t;
    else
      b[i] = max(b[i - 1] + 1, a[i] + t);
  for (int i = (int)(1); i <= (int)(n); i++)
    if (x[i] + 1 <= n && a[x[i] + 1] + t <= b[x[i]]) return puts("No"), 0;
  puts("Yes");
  for (int i = (int)(1); i <= (int)(n); i++) printf("%lld ", b[i]);
}
