#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const int INF = 1 << 28;
const long long INFL = 1LL << 62;
const double INFD = 1e+20;
int GetInt() {
  int r = 0, c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') return -GetInt();
  for (; c > 32; r = (r << 1) + (r << 3) + c - '0', c = getchar())
    ;
  return r;
}
int main() {
  long long k, b, n, t;
  cin >> k >> b >> n >> t;
  int x = 1;
  while (n && k * x + b <= t) {
    x = k * x + b;
    n--;
  }
  cout << n << endl;
}
