#include <bits/stdc++.h>
using namespace std;
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
inline int myrand() { return abs((rand() << 15) ^ rand()); }
inline int rnd(int x) { return myrand() % x; }
const int INF = (int)1e9 + 1;
const long double EPS = 1e-9;
void precalc() {}
int gcd(int a, int b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
int getFunc(const pair<int, int> &a, const pair<int, int> &b) {
  return gcd(abs(a.first - b.first), abs(a.second - b.second));
}
long long inside(int n, pair<int, int> *ps, long long G = -1) {
  if (n < 3) {
    return 0;
  }
  bool needG = (G == -1);
  if (needG) {
    G = 0;
  }
  long long S2 = 0;
  for (int i = 0; i < n; ++i) {
    int in = (i == n - 1 ? 0 : (i + 1));
    int dx = ps[in].first - ps[i].first;
    S2 += (long long)dx * (ps[in].second + ps[i].second);
    if (needG) {
      G += getFunc(ps[i], ps[in]);
    }
  }
  S2 = abs(S2);
  long long res = S2 + 2 - G;
  assert(!(res & 1));
  return res / 2;
}
const int maxn = (int)1e5 + 10;
pair<int, int> ps[maxn * 2];
int n;
bool read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &ps[i].first, &ps[i].second);
  }
  return 1;
}
long long cnts[maxn];
int gcdn[maxn * 2];
int gcdc[maxn];
void solve() {
  for (int i = 0; i < n; ++i) {
    cnts[i] = 0;
    ps[n + i] = ps[i];
  }
  for (int i = 0; i < n; ++i) {
    gcdc[i] = gcdn[i] = gcdn[i + n] = getFunc(ps[i], ps[i + 1]);
  }
  long long whole = inside(n, ps);
  long double up, down;
  long double prob;
  if (n <= 100) {
    up = 1;
    for (int i = 0; i < n; ++i) {
      up *= 2;
    }
    down = up - (long double)(n * (n - 1) / 2 + n + 1);
    up /= 8;
    up -= 1;
  } else {
    prob = 1;
    prob /= 8;
  }
  pair<int, int> tmp[3];
  long double res = whole;
  for (int k = 3; k < 60; ++k) {
    if (n <= 100) {
      prob = up / down;
    }
    if (0 && prob * whole * n * 2 <= 1e-9) {
      break;
    }
    for (int i = 0; i < n; ++i) {
      long long &cnt = cnts[i];
      tmp[0] = ps[i], tmp[1] = ps[i + k - 2], tmp[2] = ps[i + k - 1];
      int ngcd = getFunc(ps[i], ps[i + k - 1]);
      cnt += inside(3, tmp) + ngcd - 1;
      gcdc[i] = ngcd;
      res -= prob * cnt;
    }
    if (n <= 100) {
      up -= 1;
      up /= 2;
    } else {
      prob /= 2;
    }
  }
  printf("%.18f\n", (double)res);
}
int main() {
  srand(rdtsc());
  precalc();
  while (1) {
    if (!read()) {
      break;
    }
    solve();
  }
  return 0;
}
