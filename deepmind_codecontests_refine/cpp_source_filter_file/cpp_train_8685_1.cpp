#include <bits/stdc++.h>
#pragma comment(linker, "/stack:32000000")
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
int n, m;
int a[10][10];
bool issq(long long x) {
  int sq = (int)(sqrt(x + .0) + .5);
  return (long long)sq * sq == x;
}
bool check() {
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    long long v1 = 0;
    for (int j = 0; j < m; ++j) {
      v1 += a[i][j] * (long long)a[i][j];
    }
    ok &= issq(v1);
    if (!ok) return ok;
  }
  for (int j = 0; j < m; ++j) {
    long long v1 = 0;
    for (int i = 0; i < n; ++i) {
      v1 += a[i][j] * (long long)a[i][j];
    }
    ok &= issq(v1);
    if (!ok) return ok;
  }
  return ok;
}
void rec(int i, int j) {
  if (i == n) {
    if (check()) {
      for (int p1 = 0; p1 < n; ++p1) {
        for (int p2 = 0; p2 < m; ++p2) printf("%d ", a[p1][p2]);
        printf("\n");
      }
      printf("\n");
    }
    return;
  }
  int ni = i;
  int nj = j + 1;
  if (nj == m) nj = 0, ni++;
  for (int iter = 0; iter < 9; ++iter) {
    a[i][j] = iter + 1;
    rec(ni, nj);
  }
}
vector<int> solve(int n) {
  if (n == 1) {
    vector<int> r;
    r.push_back(1);
    return r;
  }
  if (n == 2) {
    vector<int> r;
    r.push_back(3);
    r.push_back(4);
    return r;
  }
  if (n & 1) {
    vector<int> r;
    for (int i = 0; i < n - 1; ++i) r.push_back(1);
    r.push_back((n - 2) / 2);
    return r;
  } else {
    vector<int> r;
    for (int i = 0; i < n - 2; ++i) r.push_back(1);
    r.push_back(2);
    r.push_back((n + 1) / 2);
    return r;
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> v1 = solve(n);
  vector<int> v2 = solve(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int res = v1[i] * v2[j];
      printf("%d ", res);
    }
    printf("\n");
  }
  return 0;
}
