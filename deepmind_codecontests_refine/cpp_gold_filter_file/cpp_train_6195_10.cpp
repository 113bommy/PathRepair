#include <bits/stdc++.h>
using namespace std;
struct point {
  long long v, d, p, nul;
} a[4005];
bool vis[4005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].v >> a[i].d >> a[i].p;
    a[i].nul = i;
  }
  queue<point> q;
  long long vd, vh;
  for (int i = 1; i <= n; i++) {
    if (a[i].p >= 0) {
      q.push(a[i]);
      vd = a[i].v;
      vh = 0;
      for (int j = i + 1; j <= n; j++) {
        if (a[j].p >= 0) {
          a[j].p -= (vd + vh);
          vd = max(0LL, vd - 1);
          if (a[j].p < 0) vh += a[j].d;
        }
      }
    }
  }
  cout << q.size() << endl;
  cout << q.front().nul;
  q.pop();
  while (!q.empty()) {
    cout << ' ' << q.front().nul;
    q.pop();
  }
  cout << endl;
  return 0;
}
