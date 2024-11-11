#include <bits/stdc++.h>
using namespace std;
vector<int> e[100005];
int app[100005], n;
long long ms[100005], rs[100005], tr;
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) {
  return ((a / gcd(max(a, b), min(a, b))) * b);
}
void cal(int p, int f) {
  ms[p] = 1;
  long long mn = (1LL << 62), s = e[p].size() - ((p == 1) ? 0 : 1);
  for (int i = 0; i < e[p].size(); i++) {
    if (e[p][i] != f) {
      cal(e[p][i], p);
      ms[p] = lcm(ms[p], ms[e[p][i]]);
      mn = min(mn, rs[e[p][i]]);
    }
  }
  if (s == 0) {
    rs[p] = app[p];
    return;
  }
  rs[p] = mn;
  if (rs[p] < ms[p]) {
    ms[p] = 1;
    rs[p] = 0;
  }
  rs[p] = (mn / ms[p] * ms[p]) * s;
  ms[p] = ms[p] * s;
}
int main() {
  scanf("%d", &n);
  long long tt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &app[i]);
    tt += app[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    e[a].push_back(b);
    e[b].push_back(a);
  }
  cal(1, 0);
  printf("%I64d", tt - rs[1]);
}
