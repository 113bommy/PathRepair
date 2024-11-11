#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Node {
  pair<int, int> p;
  int id;
  bool operator<(const Node &d) const { return p < d.p; }
} a[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int mi[maxn];
    int ans[maxn] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].p.first);
      a[i].id = i;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].p.second);
      a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    mi[n] = a[n].p.second;
    for (int i = n - 1; i >= 1; i--) {
      mi[i] = min(mi[i + 1], a[i].p.second);
    }
    int nowpos = n;
    for (int i = n - 1; i >= 1; i--) {
      if (a[i].p.second > mi[nowpos]) nowpos = i;
    }
    for (int i = nowpos; i <= n; i++) {
      ans[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i];
    }
    cout << '\n';
  }
}
