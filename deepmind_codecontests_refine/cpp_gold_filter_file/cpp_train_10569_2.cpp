#include <bits/stdc++.h>
using namespace std;
void Freopen() {
  freopen(
      "title"
      ".in",
      "r", stdin);
  freopen(
      "title"
      ".out",
      "w", stdout);
}
int read() {
  int g = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    g = g * 10 + ch - '0';
    ch = getchar();
  }
  return g * f;
}
const int N = 1.5e5 + 5;
int n, d[N], t[N], id[N], p[N];
long long T, L[N], R[N];
double maxn[N];
bool check(double mid) {
  int las = 0;
  for (int i = (1); i <= (n); i++) {
    int x = p[i];
    if (d[x] != d[p[i - 1]]) las = i - 1;
    double re = d[x] * (1 - mid * R[x] / T);
    if (re < maxn[las]) return false;
    re = d[x] * (1 - mid * (L[x] + t[x]) / T);
    maxn[i] = max(maxn[i - 1], re);
  }
  return true;
}
signed main() {
  n = read();
  for (int i = (1); i <= (n); i++) d[i] = read();
  for (int i = (1); i <= (n); i++) t[i] = read(), T += t[i];
  for (int i = (1); i <= (n); i++) id[i] = i;
  sort(id + 1, id + n + 1,
       [](int a, int b) { return 1ll * d[a] * t[b] > 1ll * d[b] * t[a]; });
  int las = 0;
  long long pre = 0;
  for (int i = (1); i <= (n); i++) {
    int x = id[i];
    if (1ll * d[x] * t[id[i + 1]] != 1ll * d[id[i + 1]] * t[x]) {
      for (int j = (las + 1); j <= (i); j++) L[id[j]] = pre;
      for (int j = (las + 1); j <= (i); j++) pre += t[id[j]];
      for (int j = (las + 1); j <= (i); j++) R[id[j]] = pre;
      las = i;
    }
  }
  for (int j = (las + 1); j <= (n); j++) L[id[j]] = pre;
  for (int j = (las + 1); j <= (n); j++) pre += t[id[j]];
  for (int j = (las + 1); j <= (n); j++) R[id[j]] = pre;
  for (int i = (1); i <= (n); i++) p[i] = i;
  sort(p + 1, p + n + 1, [](int a, int b) { return d[a] < d[b]; });
  double l = 0, r = 1, ans = 0;
  for (int ca = (1); ca <= (60); ca++) {
    double mid = (l + r) / 2;
    if (check(mid))
      ans = mid, l = mid;
    else
      r = mid;
  }
  cout << fixed << setprecision(10) << ans;
  return signed();
}
