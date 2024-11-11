#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-18;
const double DEPS = 1e-9;
const long double PI = 3.141592653589793238;
const long long MOD = 998244353;
const int N = (int)(5e5) + 10;
void inp() {}
void out() {}
long long gcd(long long fx, long long fy) {
  if (!fy) return fx;
  return gcd(fy, fx % fy);
}
inline void fill(int* ar, int sz, int val) {
  for (int i = 0; i < sz; i++) {
    ar[i] = val;
  }
}
int n, m, las[N], fw[N], a[N], mn[N], mx[N], fx[N];
void update(int idx, int val) {
  for (; idx < N; idx += idx & -idx) {
    fw[idx] += val;
  }
}
int get(int idx) {
  int sm = 0;
  for (; idx > 0; idx -= idx & -idx) {
    sm += fw[idx];
  }
  return sm;
}
int main() {
  inp();
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    scanf("%d", a + i);
    if (las[a[i]]) continue;
    las[a[i]] = i;
    mx[a[i]] = a[i] + get(n) - get(a[i]);
    update(a[i], 1);
  }
  for (int i = 1; i <= n; i++) {
    if (!las[i]) {
      mn[i] = i;
      mx[i] = i + get(n) - get(i);
    }
    las[i] = 0;
  }
  memset(fw, 0, sizeof(fw));
  for (int i = 1; i <= m; i++) {
    int& p = a[i];
    if (las[p]) {
      mx[p] = max(mx[p], get(i) - get(las[p] + 1) + 1);
      update(las[p], -1);
    }
    update(i, 1);
    las[p] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (las[i]) mx[i] = max(mx[i], get(m) - get(las[i]) + 1);
    printf("%d %d\n", max(1, mn[i]), mx[i]);
  }
}
