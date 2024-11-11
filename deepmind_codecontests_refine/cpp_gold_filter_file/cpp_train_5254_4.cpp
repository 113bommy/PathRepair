#include <bits/stdc++.h>
const unsigned long long inf = 1LL << 61;
const double eps = 1e-5;
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
struct Node {
  int x, y;
};
struct cmp {
  bool operator()(Node a, Node b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x > b.x;
  }
};
bool cmp(int a, int b) { return a > b; }
int a[200010];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int y = a[n - 1];
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (i == 0 || a[i] != a[i - 1]) {
        int x = 2 * a[i];
        for (int j = x; j <= y; j += a[i]) {
          int id = lower_bound(a, a + n, j) - a;
          if (id > 0) ans = max(ans, (a[id - 1] % a[i]));
        }
        ans = max(ans, (a[n - 1] % a[i]));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
