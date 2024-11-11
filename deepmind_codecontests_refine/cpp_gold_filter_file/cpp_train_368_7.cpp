#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long a, b;
  bool operator<(const edge &P) const {
    if (b == P.b) return a < P.a;
    return b < P.b;
  }
};
int a[200004], b[200004];
set<edge> hal, ful;
set<edge>::iterator it;
edge gr;
int main() {
  int i, j, k, l, m, n, w, tot;
  scanf("%d%d%d", &n, &w, &tot);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) scanf("%d", &b[i]);
  j = 1;
  long long ans = 0, cal = 0, time = 0;
  for (int i = 1; i <= n; i++) {
    gr.a = i;
    gr.b = b[i];
    hal.insert(gr);
    cal += a[i];
    time += (b[i] + 1) / 2;
    if (hal.size() > w) {
      it = hal.begin();
      hal.erase(*it);
      ful.insert(*it);
      time += b[(it)->a];
      time -= (b[(it)->a] + 1) / 2;
    }
    while (time > tot && j <= i) {
      gr.a = j;
      gr.b = b[j];
      if (hal.find(gr) != hal.end()) {
        hal.erase(gr);
        time -= (b[j] + 1) / 2;
        cal -= a[j];
        if (ful.size()) {
          it = ful.end();
          it--;
          ful.erase(*it);
          time -= b[it->a];
          time += (b[it->a] + 1) / 2;
          hal.insert(*it);
        }
      } else if (ful.find(gr) != ful.end()) {
        ful.erase(gr);
        time -= gr.b;
        cal -= a[gr.a];
      }
      j++;
    }
    ans = max(ans, cal);
  }
  cout << ans << endl;
}
