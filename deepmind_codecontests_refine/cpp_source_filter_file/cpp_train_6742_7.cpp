#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, l;
  cin >> n >> m >> l;
  int box = n;
  long long t = n * m, s = 0;
  long long a[5 + t];
  for (int i = 1; i <= n * m; ++i) cin >> a[i];
  sort(a + 1, 1 + a + t);
  if (n == 1) cout << a[1] << endl, exit(0);
  long long b[t + 5];
  b[1] = 0;
  for (int i = 2; i <= t; ++i) {
    b[i] = (b[i - 1] + a[i] - a[i - 1]);
  }
  long long last = t;
  for (int i = 1; i <= t; ++i) {
    if (b[i] > l) {
      last = i - 1;
      break;
    }
  }
  if (last < n)
    cout << 0 << endl;
  else if (last == n) {
    long long sum = 0;
    while (last >= 1) {
      sum += a[last--];
    }
    cout << sum << endl;
  } else {
    long long beshi = (last - n);
    long long per_box1 = beshi / m;
    long long per_box2 = per_box1;
    long long extra = beshi % m, ans = 0;
    long long Box = 1;
    for (int i = 1; Box < last; ++i) {
      ans += a[Box++];
      for (int j = 1; j < m; ++j) {
        if (last - Box > n - i)
          Box++;
        else
          break;
      }
    }
    cout << ans << endl;
  }
}
