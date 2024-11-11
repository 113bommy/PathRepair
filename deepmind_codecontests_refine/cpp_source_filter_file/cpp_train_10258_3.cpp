#include <bits/stdc++.h>
using namespace std;
char op[600001];
long long id[600001], ans[600001], s[600001];
long long n, m, t;
bool cmp(long long x, long long y) {
  long long pa, pb;
  if (op[x] == 'L') {
    pa = ((s[x] - t) % m + m) % m;
  } else
    pa = (s[x] + t) % m;
  if (op[y] == 'L') {
    pb = ((s[y] - t) % m + m) % m;
  } else
    pb = (s[y] + t) % m;
  if (pa != pb) return pa < pb;
  return op[x] == 'L';
}
long long id2[300001];
bool cmp2(long long x, long long y) {
  if (s[x] != s[y]) {
    return s[x] < s[y];
  }
  return op[x] == 'L';
}
signed main() {
  cin >> n >> m >> t;
  for (long long i = 0; i < n; i++) {
    cin >> s[i] >> op[i];
    s[i]--;
    id[i] = id2[i] = i;
  }
  sort(id, id + n, cmp);
  sort(id2, id2 + n, cmp2);
  long long pos = 0;
  if (id[0] == 'L') {
    long long x = s[0] - t;
    for (long long i = 0; i < n; i++) {
      if (op[i] == 'R') {
        long long y = s[i] + t;
        if (s[i] > s[0]) y -= m;
        if (y < x) continue;
        pos = (pos + (y - x) / m + 1) % n;
      }
    }
    pos = (n - pos) % n;
  } else {
    long long x = s[0] + t;
    for (long long i = 0; i < n; i++) {
      if (op[i] == 'L') {
        long long y = s[i] - t;
        if (s[i] < s[0]) y += m;
        if (y > x) continue;
        pos = (pos + (x - y) / m + 1) % n;
      }
    }
  }
  long long p = 0;
  for (long long i = 0; i < n; i++) {
    if (id2[i] == 0) p = i;
  }
  p = (p + pos) % n;
  long long q = 0;
  for (long long i = 0; i < n; i++) {
    if (id[i] == 0) q = i;
  }
  for (long long i = 0; i < n; i++) {
    long long j = id[(q + i) % n];
    long long x = (q + i) % n, y;
    if (op[j] == 'L')
      y = ((s[j] - t) % m + m) % m;
    else
      y = (s[j] + t) % m;
    long long z = id2[(p + i) % n];
    ans[z] = y + 1;
  }
  for (long long i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}
