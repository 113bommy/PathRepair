#include <bits/stdc++.h>
#pragma warning(disable : 4996)
const int mod = 1e9 + 7;
const double PI = 3.1415926535897932384626433832795;
using namespace std;
int n, m, p[100007], t[100007];
map<int, int> mp;
int find(int v) {
  int pr;
  if (p[v] == v) {
    return v;
  }
  pr = p[v];
  p[v] = find(pr);
  t[v] ^= t[pr];
  return p[v];
}
int add(int v1, int v2, int t0) {
  int p1 = find(v1), p2 = find(v2);
  if (p1 == p2) {
    if (t0 ^ t[v1] ^ t[v2] == 1) {
      return 0;
    }
    return 1;
  } else {
    t[p2] = t0 ^ t[v1] ^ t[v2];
    p[p2] = p1;
    return 1;
  }
}
void sol() {
  int i, a, b, x, pr, ans, s;
  for (i = 0; i < 100007; i++) {
    p[i] = i;
    t[i] = 0;
  }
  for (i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &x);
    find(3);
    if (add(a - 1, b - 1, x) == 0) {
      printf("0\n");
      return;
    }
  }
  ans = 0;
  for (i = 0; i < n; i++) {
    pr = find(i);
    if (mp[pr] == 0) {
      mp[pr] = 1;
      ans++;
    }
  }
  s = 1;
  for (i = 0; i < ans - 1; i++) s = (s * 2) % mod;
  printf("%d", s);
}
int main() {
#pragma comment(linker, "/STACK:268435456")
  scanf("%d%d", &n, &m);
  sol();
  return 0;
}
