#include <bits/stdc++.h>
using namespace std;
int read() {
  int num = 0;
  bool f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    f = (ch == '-');
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    num = (num << 1) + (num << 3) + ch - '0';
    ch = getchar();
  }
  return f ? -num : num;
}
int n, m, pos;
long long ans;
const int MAXN = 2e5 + 11;
long long a[MAXN], w[MAXN];
int work() {
  n = read(), m = read();
  ans = 0;
  pos = m + 1;
  for (int(i) = (1); (i) <= (n); (i)++) a[i] = read();
  for (int(i) = (1); (i) <= (m); (i)++) w[i] = read();
  sort(w + 1, w + m + 1);
  sort(a + 1, a + n + 1, greater<int>());
  int t = 1;
  for (int(i) = (1); (i) <= (m); (i)++) {
    if (w[i] == 1)
      ans += a[i] * 2;
    else {
      pos = i;
      break;
    }
  }
  int l = pos, r = n;
  for (int(i) = (m); (i) >= (pos); (i)--) {
    ans += a[l] + a[r];
    r -= w[i] - 1;
  }
  return printf("%lld\n", ans);
}
int main() {
  for (int(_) = (read()); (_) >= (1); (_)--) {
    work();
  }
  return 0;
}
