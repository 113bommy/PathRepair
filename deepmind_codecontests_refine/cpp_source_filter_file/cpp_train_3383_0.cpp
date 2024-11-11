#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, c, d, e;
};
bool cmp(node first, node sec) {
  if (first.b != sec.b) return first.b < sec.b;
  return first.a < sec.a;
}
bool operator<(node left, node right) {
  if (left.a != right.a) return left.a < right.a;
  return left.b < right.b;
}
int palin(long long x) {
  long long no[100], z, r, i, j, a = 0;
  z = x;
  while (z) {
    r = z % 10;
    no[a] = r;
    a++;
    z = z / 10;
  }
  for (i = 0; i < a; i++) {
    j = a - 1 - i;
    if (no[j] != no[i]) return 0;
  }
  return 1;
}
long long mark[2000000];
int prime(long long x) {
  long long i, z;
  mark[1] = 1;
  for (i = 2; i <= sqrt(x); i++) {
    if (mark[i] == 0) {
      z = i + i;
      while (z <= x) {
        mark[z] = 1;
        z += i;
      }
    }
  }
  return 0;
}
int main() {
  long long i, n = 1500000, p = 1, pr = 0, a, b, flag = 0, ans;
  cin >> a >> b;
  prime(1500000);
  i = 2;
  for (i = 2; i <= 1500000; i++) {
    p += palin(i);
    pr += 1 - mark[i];
    if (b * pr <= a * p) ans = i;
  }
  cout << ans;
  return 0;
}
