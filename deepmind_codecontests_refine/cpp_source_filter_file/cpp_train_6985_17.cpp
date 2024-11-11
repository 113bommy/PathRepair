#include <bits/stdc++.h>
using namespace std;
set<long long> s;
struct edges {
  long long x, v1, v2;
};
edges a[500001];
long long n, m, k, c[500001], parent[500001], size_, count_, ans;
bool cmp(edges x, edges y) { return x.x < y.x; }
long long find(long long x) {
  if (parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}
void add(long long u, long long v) {
  s.insert(u), s.insert(v);
  if (find(u) != find(v)) {
    parent[find(u)] = find(v);
    size_--;
  }
}
long long fpow(long long x, long long y) {
  if (y) {
    if (y & 1) {
      return x * fpow(x, y - 1) % 1000000007;
    } else {
      return fpow(x * x % 1000000007, y / 2);
    }
  } else {
    return 1;
  }
}
int main() {
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> c[i];
    parent[i] = i;
  }
  for (long long i = 1; i <= m; i++) {
    cin >> a[i].v1 >> a[i].v2;
    a[i].x = c[a[i].v1] ^ c[a[i].v2];
  }
  sort(a + 1, a + m + 1, cmp);
  for (long long i = 1; i <= m;) {
    long long j = i;
    size_ = n;
    for (auto x : s) {
      parent[x] = x;
    }
    s.clear();
    while (j <= m && a[j].x == a[i].x) {
      add(a[j].v1, a[j].v2);
      j++;
    }
    i = j;
    count_++;
    ans += fpow(2, size_);
    ans %= 1000000007;
  }
  cout << (ans + (fpow(2, n) + 1000000007 - count_) * fpow(2, k) % 1000000007) %
              1000000007;
  return 0;
}
