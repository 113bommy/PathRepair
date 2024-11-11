#include <bits/stdc++.h>
using namespace std;
long long t[100005], sz[100005], cic[100005];
long long d(long long a) {
  if (a == t[a]) return t[a];
  t[a] = d(t[a]);
  return t[a];
}
bool same(long long a, long long b) {
  a = d(a);
  b = d(b);
  return (a == b);
}
void unite(long long a, long long b) {
  a = d(a);
  b = d(b);
  if (sz[a] > sz[b]) {
    t[b] = a;
    cic[a] += cic[b];
    sz[a] += sz[b];
  } else {
    cic[b] += cic[a];
    t[a] = b;
    sz[b] += sz[a];
  }
}
int main() {
  long long n, m, a, b;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    sz[i] = 1;
    t[i] = i;
    cic[i] = 0;
  }
  long long ans = 1;
  for (long long i = 1; i <= m; i++) {
    cin >> a >> b;
    if (same(a, b) == false) {
      unite(a, b);
      cout << (ans - 1 + 1000000007) % 1000000007 << "\n";
    } else {
      ans *= 2;
      ans %= 1000000007;
      cout << (ans - 1 + 1000000007) % 1000000007 << "\n";
    }
  }
  return 0;
}
