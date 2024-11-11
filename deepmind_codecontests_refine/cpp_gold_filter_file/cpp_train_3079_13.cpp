#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
struct Segment {
  int l, r;
  int id;
  bool operator<(const Segment &o) const { return l < o.l; }
} a[maxn];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i].l, &a[i].r);
    a[i].id = i + 1;
  }
  sort(a, a + n);
  priority_queue<int, vector<int>, greater<int> > que;
  int ans = -1;
  int L, R;
  for (int i = 0; i < n; i++) {
    que.push(a[i].r);
    while (que.size() && que.top() == a[i].l - 1) {
      que.pop();
    }
    while (que.size() > k) {
      que.pop();
    }
    if (que.size() == k) {
      int tmp = que.top() - a[i].l + 1;
      if (tmp > ans) {
        ans = tmp;
        L = a[i].l;
        R = que.top();
      }
    }
  }
  if (ans == -1) {
    cout << 0 << endl;
    for (int i = 1; i <= k; i++) {
      printf("%d ", i);
    }
  } else {
    cout << ans << endl;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i].l <= L && a[i].r >= R) {
        printf("%d ", a[i].id);
        cnt++;
        if (cnt == k) break;
      }
    }
  }
  return 0;
}
