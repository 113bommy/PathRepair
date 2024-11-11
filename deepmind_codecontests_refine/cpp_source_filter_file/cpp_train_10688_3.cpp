#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y, id;
  P() {}
  P(int x, int y, int id) : x(x), y(y), id(id) {}
} p[100100];
long long cal(int x, int y) { return 1LL * x * x + 1LL * y * y; }
int b[100100];
int main() {
  ios::sync_with_stdio(0);
  srand(time(0));
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y, p[i].id = i;
    random_shuffle(p, p + n);
    P ans(0, 0, 0);
    for (int i = 0; i < n; i++) {
      if (cal(ans.x + p[i].x, ans.y + p[i].y) <
          cal(ans.x - p[i].x, ans.y - p[i].y)) {
        b[p[i].id] = 1;
        ans.x += p[i].x;
        ans.y += p[i].y;
      } else {
        b[p[i].id] = -1;
        ans.x -= p[i].x;
        ans.y -= p[i].y;
      }
    }
    for (int i = 0; i < n; i++) printf("%d%c", b[i], " \n"[i == n - 1]);
  }
  return 0;
}
