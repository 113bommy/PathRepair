#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 10;
const double Pi = acos(-1);
inline long long read() {
  long long x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
long long n, k, tmp;
long long a[N], b[N];
struct Node {
  long long v, id;
};
priority_queue<Node> pq;
bool operator<(Node a, Node b) { return a.v < b.v; }
void File() { return; }
long long ck(long long x) {
  long long res = 0;
  tmp = 0;
  while (pq.size()) pq.pop();
  for (register long long i = 1; i <= n; ++i) {
    pq.push((Node){-(a[i] - x), 1});
    Node y = pq.top();
    if (-y.v + b[i] < 0) {
      tmp += -y.v + b[i];
      res += y.id;
      pq.pop();
      pq.push((Node){b[i], 0});
    }
  }
  return res;
}
signed main() {
  File();
  n = read(), k = read();
  for (register long long i = 1; i <= n; ++i) a[i] = read();
  for (register long long i = 1; i <= n; ++i) b[i] = read();
  long long l = 0, r = 1e9;
  while (l < r) {
    long long mid = (l + r) >> 1;
    long long ans = ck(mid);
    if (ans < k)
      l = mid + 1;
    else if (ans > k)
      r = mid - 1;
    else
      l = r = mid;
  }
  long long ans = ck(l);
  if (ans != k) tmp += (k - ans) * l;
  tmp += k * l;
  printf("%lld\n", tmp);
  return 0;
}
