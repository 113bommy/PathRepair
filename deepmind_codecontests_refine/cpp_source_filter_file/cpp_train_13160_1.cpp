#include <bits/stdc++.h>
using namespace std;
struct pt {
  int a, id;
};
bool comp(pt a, pt b) { return a.a < b.a || (a.a == b.a && a.id < b.id); }
pt w[300001];
int ans[300001];
int main() {
  int n, i, mx, cur;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> w[i].a, w[i].id = i;
  sort(w + 1, w + n + 1, comp);
  cur = w[1].a;
  for (i = 1; i <= n; i++) {
    if (w[i].a > cur)
      ans[w[i].id] = w[i].a, cur = w[i].a;
    else
      ans[w[i].id] = cur++;
  }
  for (i = 1; i <= n; i++) cout << ans[i] << " ";
}
