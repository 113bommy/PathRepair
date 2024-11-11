#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > q;
int n, m, sum1;
struct ww {
  int a, b;
} w[200010];
char s[400010];
int cmp(ww a, ww b) { return a.b < b.b; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &w[i].b);
  for (int i = 0; i < n; i++) w[i].a = i + 1;
  sort(w, w + n, cmp);
  scanf("%s", s);
  int j = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == '1') {
      printf("%d ", q.top().second);
      q.pop();
    } else {
      q.push(make_pair(w[j].b, w[j].a));
      j++;
      printf("%d ", w[j - 1].a);
    }
  }
}
