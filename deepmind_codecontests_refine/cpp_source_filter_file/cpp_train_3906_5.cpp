#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
const int inf = 1 << 28;
struct node {
  int f, t;
  bool operator<(const node& x) const {
    return f > x.f || (f == x.f && t < x.t);
  }
} p[maxn];
int main() {
  int n, s;
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].f >> p[i].t;
  }
  p[0] = node{0, 0};
  sort(p, p + n + 1);
  int time = 0;
  int last = s;
  for (int i = 1; i <= n; i++) {
    if (i < n && p[i].f == p[i + 1].f) continue;
    time += last - p[i].f;
    if (time < p[i].t) time += p[i].t - time;
    last = p[i].f;
  }
  cout << time << endl;
  return 0;
}
