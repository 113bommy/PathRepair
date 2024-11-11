#include <bits/stdc++.h>
using namespace std;
struct P {
  int x1, x2, y1, y2;
  bool c;
  void in() {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    c = 1;
  }
} p[132700];
P pre[132700], suf[132700];
P mer(P p1, P p2) {
  P ans;
  if (!p1.c || !p2.c) {
    ans.c = 0;
    return ans;
  }
  ans.x1 = max(p1.x1, p2.x1);
  ans.y1 = max(p1.y1, p2.y1);
  ans.x2 = min(p1.x2, p2.x2);
  ans.y2 = min(p1.y2, p2.y2);
  ans.c = 0;
  if (ans.x2 >= ans.x1 && ans.y2 >= ans.y1) ans.c = 1;
  return ans;
}
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) p[i].in();
  pre[0] = p[0];
  suf[n - 1] = p[n - 1];
  for (int i = 1; i < n; i++) pre[i] = mer(p[i], pre[i - 1]);
  for (int i = n - 2; i >= 0; i--) suf[i] = mer(p[i], suf[i + 1]);
  for (int i = 1; i < n - 1; i++) {
    P pp = mer(pre[i - 1], suf[i + 1]);
    if (pp.c) {
      cout << pp.x1 << " " << pp.y1 << endl;
      return 0;
    }
  }
  if (pre[n - 2].c) {
    cout << pre[n - 2].x1 << " " << pre[n - 2].y1;
    return 0;
  }
  if (suf[1].c) {
    cout << suf[1].x1 << " " << suf[1].y1;
    return 0;
  }
}
