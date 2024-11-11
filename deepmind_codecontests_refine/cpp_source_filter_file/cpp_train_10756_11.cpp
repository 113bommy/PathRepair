#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 100005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  string s = "/home/jslijin/jslijin/code/";
  freopen((s + "code.in").c_str(), "r", stdin);
  freopen((s + "code.out").c_str(), "w", stdout);
}
int x, y, n, a, b, ret;
int op = 1;
int main() {
  scanf("%d%d%d%d", &x, &y, &a, &b);
  if (x + a <= y && y <= x + b) return 0 * printf("FIRST\n%d\n", y);
  if (a <= 0 && 0 <= b) return 0 * printf("DRAW\n");
  n = y - x;
  if (b < 0) a = -a, b = -b, n = -n, op = -1;
  if (n < 0) return 0 * printf("DRAW\n");
  n %= a + b;
  if (!n) return 0 * printf("SECOND\n");
  if (a > b) swap(a, b);
  if (b <= n && n <= a) return 0 * printf("FIRST\n%d\n", x + n * op);
  printf("DRAW\n");
  return 0;
}
