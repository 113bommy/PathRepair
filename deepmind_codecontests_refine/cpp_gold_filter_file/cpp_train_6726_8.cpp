#include <bits/stdc++.h>
using namespace ::std;
const int maxm = 21;
const int maxn = (1 << maxm);
const int mod = 1e9 + 7;
const int inf = 5e7 + 500;
int t, p;
int a[maxn];
int khone[maxn];
int minnn[maxn][maxm];
void update(int x, int val) {
  khone[x] += val;
  if (val > 0) {
    cout << "HABAHJ\n";
  }
  for (int i = 0; i <= t; i++) {
    int v = (((x >> i)));
    minnn[v][i] = min(minnn[v][i], khone[x]);
  }
}
int finds(int l) { return khone[l]; }
int findss(int k, int i) { return minnn[k][i]; }
inline int f(int a, int b) {
  for (int i = t; i >= 0; i--) {
    int h1 = (b >> (t - i));
    int h2 = (a & ((1 << i) - 1));
    if (h1 == h2) {
      return i;
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    t = s.size();
    for (int j = 0; j < t; j++) {
      a[i] *= 2;
      a[i] += (s[j] - '0');
    }
  }
  p = (1 << t) + 1;
  int zehn = inf;
  update(p - 1, -zehn - finds(p - 1) + t);
  for (int i = n - 2; i >= 0; i--) {
    int v = f(a[i], a[i + 1]);
    int u = a[i + 1];
    int o = finds(p - 1) + t + zehn;
    o = min(o, t - v + finds(u) + zehn);
    for (int j = 0; j <= t; j++) {
      int k = (a[i] & ((1 << j) - 1));
      o = min(o, t - j + zehn + findss(k, t - j));
    }
    zehn += (t - v);
    update(u, -zehn - finds(u) + o);
  }
  int v = inf;
  for (int i = 0; i < p; i++) {
    v = min(v, khone[i]);
  }
  cout << v + zehn;
}
