#include <bits/stdc++.h>
using namespace std;
long long mul(long long a, long long b) { return (a * b) % (100000007); }
long long add(long long a, long long b) { return (a + b) % (100000007); }
long long sub(long long a, long long b) {
  return (a - b + (a - b) / (100000007) * (100000007) + (100000007)) %
         (100000007);
}
void upd(long long &a, long long b) {
  a = (a % (100000007) + b % (100000007)) % (100000007);
}
int n, a[(1000000 + 10)];
int t = 0, st[(1000000 + 10)];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  for (int i = n; i >= 2; i--) {
    if (a[i] == a[i - 1])
      st[++t] = a[i], i--;
    else if (a[i] - 1 == a[i - 1])
      st[++t] = a[i - 1], i--;
  }
  long long ans = 0;
  for (int i = 2; i <= t; i += 2) {
    ans += (long long)st[i] * (long long)st[i - 1];
  }
  cout << ans << endl;
  return 0;
}
