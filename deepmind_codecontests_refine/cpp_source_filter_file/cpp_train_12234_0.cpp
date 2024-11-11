#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
const int M = 10000000;
long long a[N];
int f[N];
int cache[10000000 + 10];
int gcd(int a, int b) {
  for (int c; b; c = a, a = b, b = c % b)
    ;
  return a;
}
int find(int x) {
  if (f[x] != x) f[x] = find(f[x]);
  return f[x];
}
inline void combine(int u, int v) {
  int ru = find(u);
  int rv = find(v);
  if (ru == rv) return;
  f[rv] = ru;
}
vector<pair<int, int> > factors;
void factor_integer(int m) {
  int cnt = 0;
  while (m % 2 == 0) {
    m /= 2;
    ++cnt;
  }
  if (cnt > 0) factors.push_back(pair<int, int>(2, cnt));
  for (int i = 3; i * i <= m; i += 2)
    if (m % i == 0) {
      cnt = 0;
      while (m % i == 0) {
        m /= i;
        ++cnt;
      }
      factors.push_back(pair<int, int>(i, cnt));
    }
  if (m > 1) factors.push_back(pair<int, int>(m, 1));
}
int m, idx;
void DFS1(int dep, int cur) {
  if (cur >= m / cur) return;
  if (dep == factors.size()) {
    int x = cur;
    int y = m / x;
    int A = (x + y) / 2;
    int B = (y - x) / 2;
    if (gcd(A, B) > 1) return;
    long long tmp = (long long)A * B * 2;
    if (tmp <= M && cache[tmp] >= 0) combine(idx, cache[tmp]);
    tmp = (long long)A * A + (long long)B * B;
    if (tmp <= M && cache[tmp] >= 0) combine(idx, cache[tmp]);
    return;
  }
  if (factors[dep].first == 2)
    DFS1(dep + 1, cur);
  else {
    for (int i = 0; i <= factors[dep].second; ++i) {
      DFS1(dep + 1, cur);
      cur *= factors[dep].first;
    }
  }
}
void DFS2(int dep, int cur) {
  if (cur >= m / cur) return;
  if (dep == factors.size()) {
    int A = cur;
    int B = m / A;
    if ((A + B) % 2 == 0) return;
    if (gcd(A, B) > 1) return;
    long long tmp = (long long)B * B - (long long)A * A;
    if (tmp <= M && cache[tmp] >= 0) combine(idx, cache[tmp]);
    tmp = (long long)A * A + (long long)B * B;
    if (tmp <= M && cache[tmp] >= 0) combine(idx, cache[tmp]);
    return;
  }
  for (int i = 0; i <= factors[dep].second; ++i) {
    DFS2(dep + 1, cur);
    cur *= factors[dep].first;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  memset(cache, 255, sizeof(cache));
  for (int i = 0; i < n; ++i) {
    int x;
    f[i] = i;
    scanf("%d", &x);
    a[i] = x;
    cache[x] = i;
  }
  for (int i = 0; i < n; ++i) {
    idx = i;
    if (a[i] % 2) {
      m = a[i];
      factors.clear();
      factor_integer(m);
      DFS1(0, 1);
    } else {
      int m = a[i] / 2;
      if (m % 2) continue;
      factors.clear();
      factor_integer(m);
      DFS2(0, 1);
    }
  }
  int ret = 0;
  for (int i = 0; i < n; ++i)
    if (find(i) == i) ++ret;
  printf("%d\n", ret);
  return 0;
}
