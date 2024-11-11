#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s;
  cin >> n >> m >> s;
  long long z[600];
  memset(z, 0, sizeof(z));
  if (s % 2 == 1 && s <= n) {
    z[1] = ((long long)(s + 1) / 2 * 2 - 1) * (n - s + 1);
  }
  for (int i = 2; i <= m; i++) {
    if (i % 2 == 0) {
      continue;
    }
    int b = i;
    for (int a = 1; a <= n; a += 2) {
      for (int d = 1; d <= b; d += 2) {
        int x = s - a * b;
        if (x >= 0 && x % (d * 2) == 0) {
          int c = x / (d * 2) * 2 + a;
          if (c <= n) {
            if (x == 0) {
              if (b == d)
                z[i] += n - a + 1;
              else
                z[i] += (((long long)a + 1) / 2) * 2 * (n - a + 1);
            } else if (a == c && b == d) {
              z[i] += (n - c + 1);
            } else {
              z[i] += 2 * (n - c + 1);
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += z[i];
    for (int j = 1; j < i; j++) {
      ans += z[j];
    }
  }
  cout << ans << endl;
}
