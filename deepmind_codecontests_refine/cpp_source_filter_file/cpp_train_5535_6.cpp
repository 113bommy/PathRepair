#include <bits/stdc++.h>
using namespace std;
struct sd {
  long long s, f, tim, pos;
} num[1000000];
long long ans[1000000];
int main() {
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      cin >> num[i].s >> num[i].f >> num[i].tim;
      num[i].pos = i;
    }
    int cir = 2 * (m - 1);
    for (int i = 0; i < n; i++) {
      if (num[i].s == num[i].f) {
        ans[i] = num[i].tim;
        continue;
      }
      if (num[i].s < num[i].f) {
        int hh = (num[i].tim - num[i].s + 1);
        long long t = (num[i].tim - num[i].s + 1) / cir;
        if (hh % cir) t++;
        ans[i] = t * (cir) + num[i].f - 1;
      } else {
        long long t = num[i].tim - (m - num[i].s);
        long long tt = t / cir;
        long long s = t % cir;
        if (s > (m - 1)) {
          tt++;
        }
        ans[i] = (tt * cir) + (m - num[i].f) + m - 1;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << endl;
    }
  }
  return 0;
}
