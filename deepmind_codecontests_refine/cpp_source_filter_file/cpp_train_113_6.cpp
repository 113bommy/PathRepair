#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
bool DEBUGGING = 0;
void useiostream() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ld const pi = acos(-1.0);
ld const eps = 0.000000001;
template <class T>
bool mi(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool ma(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
void ans(int a, int b) {
  printf("! %d %d\n", a, b);
  fflush(stdout);
  exit(0);
}
int ask(int c, int d) {
  printf("? %d %d\n", c, d);
  fflush(stdout);
  int a;
  scanf("%d", &a);
  return a;
}
int main() {
  int pp = ask(0, 0);
  int a, b;
  a = b = 0;
  for (int j = 29; j >= 0; j--) {
    int p, q;
    p = ask((1 << j) ^ a, b);
    q = ask(a, (1 << j) ^ b);
    if (p == q) {
      if (pp == 1)
        a ^= 1 << j;
      else
        b ^= 1 << j, pp = p;
    } else {
      if (p == -1) a ^= 1 << j, b ^= 1 << j;
    }
  }
  ans(a, b);
  return 0;
}
