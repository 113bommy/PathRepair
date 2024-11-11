#include <bits/stdc++.h>
using namespace std;
struct line {
  long long a, b;
  bool operator<(const line& p) const {
    return a < p.a or a == p.a and b > p.b;
  }
};
vector<line> CHT[2];
long long cross(const line O, const line A, const line B) {
  return (A.a - O.a) * (B.b - O.b) - (B.a - O.a) * (A.b - O.b);
}
void add(int nx, const line X) {
  int n = CHT[nx].size();
  while (n >= 2 and cross(CHT[nx][n - 2], CHT[nx][n - 1], X) >= 0) n--;
  CHT[nx].resize(n);
  CHT[nx].push_back(X);
}
long long p(int nx, int mid, long long x) {
  return CHT[nx][mid].a * x + CHT[nx][mid].b;
}
long long query(int nx, int x) {
  int lo = 0, hi = (int)CHT[nx].size() - 1;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (p(nx, mid, x) < p(nx, mid + 1, x))
      lo = mid + 1;
    else
      hi = mid;
  }
  return p(nx, lo, x);
}
const int N = 200002;
long long a[N], L[N], R[N];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) sum += a[i] * i;
  for (int i = n; i >= 1; --i) L[i] = a[i] + L[i + 1];
  for (int i = 1; i <= n; ++i) R[i] = a[i] + R[i - 1];
  long long best = sum;
  add(0, {1, L[1]});
  for (int i = 2; i <= n; ++i) {
    long long q = query(0, a[i]);
    best = max(best, q + sum - a[i] * i - L[i]);
    add(0, {i, L[i]});
  }
  add(1, {-n, R[n]});
  for (int i = n - 1; i >= 1; --i) {
    long long q = query(1, a[i]);
    best = max(best, -q + sum - a[i] * i + R[i]);
    add(1, {-i, R[i]});
  }
  printf("%lld\n", best);
  return 0;
}
