#include <bits/stdc++.h>
using namespace std;
uint32_t n = 0;
vector<uint64_t> a;
void F(uint32_t i, uint64_t& p, uint64_t& q) {
  if (i == n) {
    p = 1;
    q = a[n];
  } else {
    uint64_t _p;
    uint64_t _q;
    F(i + 1, _p, _q);
    p = _q;
    q = a[i] * _q + _p;
  }
}
uint64_t NOD(uint64_t a, uint64_t b) {
  while (a * b)
    if (a >= b) {
      a = a % b;
    } else {
      b = b % a;
    }
  return a + b;
}
int main(void) {
  uint64_t p = 0;
  uint64_t q = 0;
  cin >> p >> q;
  uint64_t nod_pq = NOD(p, q);
  p /= nod_pq;
  q /= nod_pq;
  uint64_t c = p / q;
  p -= c * q;
  if (p == 0) {
    c--;
    p = q;
  }
  cin >> n;
  a.resize(n + 1);
  for (size_t i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << (c == a[1] - 1 && p == 1 && q == 1 ? "YES" : "NO");
  } else {
    uint64_t _p = 0;
    uint64_t _q = 0;
    F(2, _p, _q);
    uint64_t nod_pq2 = NOD(_p, _q);
    _p /= nod_pq2;
    _q /= nod_pq2;
    cout << (c == a[1] && p == _p && q == _q ? "YES" : "NO");
  }
  return 0;
}
