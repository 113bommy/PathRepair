#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double eps = 1e-8;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int _inf = -1e9 + 7;
inline int scan() {
  int m = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') m = m * 10 + c - '0', c = getchar();
  return m;
}
int N, R, V;
double V2, S;
bool ok(double t) { return S <= sin(V2 * t / 2) * R * 2 + V * t; }
int main() {
  cin >> N >> R >> V;
  V2 = 1.0 * V / R;
  for (int i = 0; i < N; i++) {
    int s, f;
    scanf("%d%d", &s, &f);
    int c = int((f - s) / (2 * pi * R));
    S = f - s - c * (2 * pi * R);
    double l = 0, r = 2 * pi / V2;
    for (int j = 0; j < 50; j++) {
      double m = (l + r) / 2;
      if (ok(m))
        r = m;
      else
        l = m;
    }
    printf("%.10lf\n", l + c * 2 * pi / V2);
  }
  return 0;
}
