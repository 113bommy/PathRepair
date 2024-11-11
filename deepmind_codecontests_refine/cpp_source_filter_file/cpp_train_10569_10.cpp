#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void chkmax(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
inline void chkmin(T& x, U y) {
  if (y < x) x = y;
}
const int MAXN = 222222;
int p[MAXN], t[MAXN], q[MAXN], id1[MAXN], id[MAXN];
long long sum[MAXN];
double x[MAXN];
long long cross(int u, int v) {
  return (long long)p[u] * t[v] - (long long)p[v] * t[u];
}
bool cmp(int u, int v) {
  long long A = (long long)p[u] * t[v], B = (long long)p[v] * t[u];
  if (A != B) {
    return A > B;
  }
  return p[u] < p[v];
}
bool cmp1(int u, int v) { return p[u] < p[v]; }
int n;
long long T;
double BIT[MAXN];
void update(int x, double y) {
  for (; x <= n; x += x & -x) {
    chkmax(BIT[x], y);
  }
}
double get(int x) {
  double ret = 0;
  for (x--; x; x -= x & -x) {
    chkmax(ret, BIT[x]);
  }
  return ret;
}
bool check(double mid) {
  for (int i = 1; i <= n; i++) {
    BIT[i] = 0;
  }
  double cur = 0;
  for (int i = 1, j = 1; i <= n; i = j) {
    for (j = i; j <= n && cross(id[i], id[j]) == 0; j++) {
      double temp = get(q[id[j]]);
      double temp1 = p[id[j]] * (1.0 - mid * (double)sum[id[j]] / T);
      if (temp > temp1 + 1e-8) {
        return 0;
      }
      update(q[id[j]], p[id[j]] * (1.0 - mid * (cur + t[id[j]]) / T));
    }
    cur = sum[id[i]];
  }
  return 1;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  T = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    T += t[i];
  }
  for (int i = 1; i <= n; i++) {
    id[i] = i;
  }
  sort(id + 1, id + n + 1, cmp);
  long long temp = 0;
  for (int i = 1, j = 1; i <= n; i = j) {
    for (j = i; j <= n && cross(id[i], id[j]) == 0; j++) {
      temp += t[id[j]];
    }
    for (int k = i; k < j; k++) {
      sum[id[k]] = temp;
    }
  }
  for (int i = 1; i <= n; i++) {
    id1[i] = i;
  }
  sort(id1 + 1, id1 + n + 1, cmp);
  for (int i = 1, j = 1, k = 1; i <= n; i = j) {
    for (j = i; j <= n && p[id1[i]] == p[id1[j]]; j++) {
      q[id1[j]] = k;
    }
    k++;
  }
  double lo = 0, hi = 1;
  for (int i = 0; i < 40; i++) {
    double mid = (lo + hi) / 2;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  printf("%.10lf\n", lo);
  return 0;
}
