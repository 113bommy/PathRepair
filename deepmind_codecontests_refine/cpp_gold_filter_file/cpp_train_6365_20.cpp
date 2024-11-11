#include <bits/stdc++.h>
using namespace std;
struct laptop {
  long long p, b, ind;
  laptop() {}
  laptop(long long a, long long b, long long c) : p(a), b(b), ind(c) {}
  bool operator<(const laptop& o) const {
    return ((long double)o.b * p > (long double)b * o.p);
  }
};
int n, k;
vector<laptop> laptops;
bool check(long long q) {
  priority_queue<laptop> pq;
  for (auto& x : laptops) {
    pq.push(x);
  }
  laptop here(0, 1, 1);
  for (int i = 0; i < k; ++i) {
    laptop u = pq.top();
    pq.pop();
    here.p = i;
    if (here < u) {
      return false;
    }
    u.p += q;
    pq.push(u);
  }
  return true;
}
long long bs() {
  const long long THIGH = 2000000000001LL;
  long long lo = 0, hi = THIGH;
  while (lo < hi) {
    long long m = (lo + hi) / 2;
    if (check(m)) {
      hi = m;
    } else {
      lo = m + 1;
    }
  }
  if (lo == THIGH) return -1;
  return lo;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  laptops.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> laptops[i].p;
    laptops[i].ind = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> laptops[i].b;
  }
  cout << bs() << endl;
  return 0;
}
