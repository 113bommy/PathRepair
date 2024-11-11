#include <bits/stdc++.h>
using namespace std;
const int dx44[5] = {0, -1, -1, 1, 1};
const int dy44[5] = {0, -1, 1, -1, 1};
const int dx4[5] = {0, -1, 0, 1, 0};
const int dy4[5] = {0, 0, 1, 0, -1};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int maxn = 5e5 + 5;
const double PI = acos(-1.0);
const long long mod = 1e9 + 7;
long long po(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
void YES() {
  puts("YES");
  exit(0);
}
void Yes() { puts("Yes"); }
void NO() {
  puts("NO");
  exit(0);
}
void No() { puts("No"); }
void one() {
  puts("-1");
  exit(0);
}
int ans[maxn];
void solve() {
  int n;
  scanf("%d", &(n));
  for (int i = 1; i <= n; i++) {
    int xx1, xx2, yy1, yy2;
    scanf("%d", &(xx1)), scanf("%d", &(xx2)), scanf("%d", &(yy1)),
        scanf("%d", &(yy2));
    xx1 = abs(xx1);
    yy1 = abs(yy1);
    if ((xx1 % 2 == 0) && (yy1 % 2 == 0)) ans[i] = 1;
    if ((xx1 % 2 == 0) && (yy1 % 2 == 1)) ans[i] = 2;
    if ((xx1 % 2 == 1) && (yy1 % 2 == 0)) ans[i] = 3;
    if ((xx1 % 2 == 1) && (yy1 % 2 == 1)) ans[i] = 4;
  }
  puts("YES");
  for (int i = 1; i <= n; i++) {
    printf("%d\n", ans[i]);
  }
}
int main() {
  solve();
  return 0;
}
