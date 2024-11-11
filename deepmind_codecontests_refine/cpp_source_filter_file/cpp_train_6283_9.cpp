#include <bits/stdc++.h>
using namespace std;
struct N1 {
  int step, pos;
  N1() {}
  N1(int x, int y) : step(x), pos(y) {}
  bool friend operator<(const N1 &a, const N1 &b) { return a.step > b.step; }
};
struct N2 {
  int step, pos;
  N2() {}
  N2(int x, int y) : step(x), pos(y) {}
  bool friend operator<(const N2 &a, const N2 &b) { return a.step < b.step; }
};
priority_queue<N1> q1;
priority_queue<N2> q2;
int a[100005], b[100005], in[100005], n;
int main() {
  while (scanf("%d", &n) != EOF) {
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      in[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &b[i]);
      if (i > in[b[i]])
        q1.push(N1(i - in[b[i]], i));
      else
        q2.push(N2(i - in[b[i]], i));
    }
    for (int i = 0; i < n; i++) {
      int ans = 1 << 30;
      if (!q1.empty()) ans = min(ans, abs(q1.top().step - i));
      if (!q2.empty()) ans = min(ans, abs(q2.top().step - i));
      printf("%d\n", ans);
      q1.push(N1(n + i - in[b[i]], 1 << 30));
      while (!q1.empty() && (q1.top().pos <= i || q1.top().step - i - 1 <= 0)) {
        if (q1.top().pos <= i) {
          q1.pop();
          continue;
        }
        q2.push(N2(q1.top().step, q1.top().pos));
        q1.pop();
      }
      while (!q1.empty() && q1.top().pos <= i) q1.pop();
    }
  }
  return 0;
}
