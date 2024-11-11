#include <bits/stdc++.h>
const long long oo = 2 * 1000 * 1000 * 1000;
const int _cnt = 1000 * 1000;
const int _p = 1000 * 1000 * 1000 + 7;
long long o(long long x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }
using namespace std;
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
int n, a, b;
int main() {
  scanf("%d%d%d", &n, &a, &b);
  printf("%d\n", ((a - 1) + b + n * 1000) % n + 1);
  return 0;
}
