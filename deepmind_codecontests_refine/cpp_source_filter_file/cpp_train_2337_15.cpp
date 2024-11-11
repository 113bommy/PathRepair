#include <bits/stdc++.h>
using namespace std;
long long mul(long long a, long long b) { return (a * b) % (100000007); }
long long add(long long a, long long b) { return (a + b) % (100000007); }
long long sub(long long a, long long b) {
  return (a - b + (a - b) / (100000007) * (100000007) + (100000007)) %
         (100000007);
}
long long n, d, x;
int i, a[(100000 + 10)], b[(100000 + 10)];
long long getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  for (i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
int q[(100000 + 10)] = {0}, h[(100000 + 10)] = {0};
int main() {
  cin >> n >> d >> x;
  initAB();
  for (int i = 0; i < n; i++)
    if (b[i]) q[++q[0]] = i;
  for (int i = 0; i < n; i++) h[a[i]] = i;
  for (int i = 0; i < n; i++) {
    int s = 30, ans = 0;
    for (int j = 0; j < 30; j++) {
      if (n - j < 0) break;
      int t = h[n - j];
      if (t <= i && b[i - t]) {
        ans = n - j;
        break;
      }
    }
    if (!ans) {
      for (int j = 1; j <= q[0]; j++) {
        int t = q[j];
        if (t > i) break;
        ans = max(ans, a[t] * b[i - t]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
