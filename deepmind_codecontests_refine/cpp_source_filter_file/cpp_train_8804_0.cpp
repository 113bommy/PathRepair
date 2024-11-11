#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct node {
  int a, b, h;
  bool operator<(const node& rhs) const {
    if (b == rhs.b) return a > rhs.b;
    return b > rhs.b;
  }
} t[N];
int n;
stack<node> tmp;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d %d", &t[i].a, &t[i].b, &t[i].h);
  sort(t, t + n);
  long long ans, now;
  ans = now = 0;
  for (int i = 0; i < n; i++) {
    while (!tmp.empty() && tmp.top().a > t[i].b) {
      now -= tmp.top().h;
      tmp.pop();
    }
    tmp.push(t[i]);
    now += t[i].h;
    ans = max(ans, now);
  }
  printf("%lld\n", ans);
  return 0;
}
