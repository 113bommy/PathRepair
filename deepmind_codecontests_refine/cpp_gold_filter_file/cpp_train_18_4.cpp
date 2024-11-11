#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
long long mid[N], a[N], mark[N], k, f1[N][2], n, g[N], h[N], p, ct, cn,
    tvn = 1, tedad[N * 4];
string s, s2;
long long saghf(long long x) { return (x / 2) + (x % 2); }
string binary(int m, int k) {
  string g = "";
  for (long long i = 0; i < k; i++) {
    g += char((m % 2) + '0');
    m = m / 2;
  }
  return g;
}
int main() {
  cin >> n;
  cn = n;
  for (long long i = 1; i < n + 1; i++)
    cin >> a[i], mark[a[i]] = i, f1[i][0] = i - 1, f1[i][1] = i + 1;
  k = saghf(n);
  for (long long i = n; i >= 1; i--) {
    mid[i] = k;
    if (i % 2 == 0) {
      if (mark[i] <= k) k = f1[k][1];
    } else {
      if (mark[i] >= k) k = f1[k][0];
    }
    f1[f1[mark[i]][0]][1] = f1[mark[i]][1];
    f1[f1[mark[i]][1]][0] = f1[mark[i]][0];
  }
  k = 0;
  for (long long i = 2; i < n; i++) {
    if (i % 2 == 0) {
      if (mid[i] == mid[i - 1])
        g[i] = g[i - 1] + (mark[i] - mid[i]) - (i / 2);
      else
        g[i] =
            g[i - 1] + (mid[i - 1] - mid[i]) + (mid[i] - mark[i]) - ((i / 2));
    } else {
      if (mid[i] == mid[i - 1])
        g[i] = g[i - 1] + (mid[i] - mark[i]) - (i / 2);
      else
        g[i] = g[i - 1] + (mark[i] - mid[i]) - (i / 2);
    }
  }
  for (long long i = 1; i < (n + 3) / 2; i++) {
    swap(a[i], a[n + 1 - i]);
    a[i] = n + 1 - a[i];
    a[n + 1 - i] = n + 1 - a[n + 1 - i];
  }
  if (n % 2 == 1) a[(n + 1) / 2] = n + 1 - a[(n + 1) / 2];
  while (cn) {
    k++;
    cn /= 2;
    tvn *= 2;
  }
  tvn /= 2;
  for (long long i = 1; i < n + 1; i++) {
    s = binary(a[i], k);
    p = 0;
    ct = tvn;
    long long t = 0, m = tvn * 2 - a[i], p1 = tvn * 2;
    s2 = binary(m, k);
    for (long long j = k - 1; j >= 0; j--) {
      if (s2[j] == '1') {
        p1 -= ct;
        t += tedad[p1];
      }
      ct /= 2;
    }
    h[n + 1 - a[i]] = t;
    ct = tvn;
    for (long long j = k - 1; j >= 0; j--) {
      if (s[j] == '1') {
        p += ct;
        tedad[p]++;
      }
      ct /= 2;
    }
  }
  for (long long i = 1; i < n + 1; i++) {
    h[i] += h[i - 1];
    cout << h[i] + g[i] << " ";
  }
}
