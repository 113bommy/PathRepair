#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, k, l[5001], r[5001], q[5001];
class Candy {
 public:
  long long b, e;
  friend bool operator<(const Candy t1, const Candy t2) {
    if (t1.b == t2.b) return t1.e < t2.e;
    return t1.b < t2.b;
  }
} candy[205];
long long Read() {
  long long k = 0, tmp = 1;
  char c = getchar();
  while (c > '9' or c < '0') {
    if (c == '-') tmp = -1;
    c = getchar();
  }
  while (c <= '9' and c >= '0') {
    k = (k << 1) + (k << 3) + (c ^ 48);
    c = getchar();
  }
  return k * tmp;
}
void Work();
int main() { Work(); }
void Work() {
  n = Read(), m = Read();
  for (int i = 1; i <= m; i++) {
    candy[i].b = Read(), candy[i].e = Read();
  }
  sort(candy + 1, candy + 1 + m);
  for (int i = 1; i <= n; i++) {
    int j;
    for (j = r[i - 1] + 1; j <= m && candy[j].b == i; j++)
      ;
    j--;
    l[i] = r[i - 1] + 1;
    r[i] = j;
  }
  for (int i = 1; i <= n; i++) {
    if (l[i] > r[i]) {
      q[i] = -1;
      continue;
    }
    q[i] = 2147483647ll * 2147483647, k = r[i] - l[i];
    for (int j = l[i]; j <= r[i]; j++) {
      q[i] = min(q[i], k * n + (candy[j].e + n - i) % n);
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = 0;
    for (int j = 1; j <= n; j++) {
      if (q[j] != -1) ans = max(ans, q[j] + (j + n - i) % n);
    }
    cout << ans << ' ';
  }
}
