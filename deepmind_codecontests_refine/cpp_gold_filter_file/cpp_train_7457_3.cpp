#include <bits/stdc++.h>
using namespace std;
int w[100010];
int a[34000];
vector<int> ps;
int phi(int n) {
  if (n == 1) return 1;
  int res = n;
  for (int i = 0; i < ps.size(); i++) {
    if (n % ps[i] == 0) {
      res = res / ps[i] * (ps[i] - 1);
      while (n % ps[i] == 0) {
        n /= ps[i];
      }
    }
  }
  if (n != 1) {
    res = res / n * (n - 1);
  }
  return res;
}
inline int md(long long n, int m) {
  if (n < m) return n;
  return (n - m) % m + m;
}
int pow(int n, int k, int m) {
  if (k == 0) return 1;
  if (k == 1) return md(n, m);
  long long res = pow(n, k / 2, m);
  res = md(res * res, m);
  if (k & 1) res = md(res * n, m);
  return res;
}
vector<int> ph;
int go(int l, int r, int k) {
  if (l >= r) return 1;
  if (ph[k] == 1) {
    return 1;
  }
  if (w[l] == 1) {
    return 1;
  }
  int p = go(l + 1, r, k + 1);
  return pow(w[l], md(p, ph[k + 1]), ph[k]);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }
  for (int i = 2; i < 34000; i++) {
    if (a[i]) continue;
    for (int j = i + i; j < 34000; j += i) {
      a[j] = i;
    }
    ps.push_back(i);
  }
  ph.push_back(m);
  while (ph.back() != 1) {
    ph.push_back(phi(ph.back()));
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l;
    printf("%d\n", go(l, r, 0) % m);
  }
  return 0;
}
