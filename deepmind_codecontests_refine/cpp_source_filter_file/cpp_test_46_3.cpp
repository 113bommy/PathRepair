#include <bits/stdc++.h>
using namespace std;
int t, n, ans, mpos;
struct node {
  int a, id;
} x[200100];
bool cmp(node a, node b) { return a.a < b.a; }
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> x[i].a;
      x[i].id = i;
    }
    sort(x + 1, x + n + 1, cmp);
    mpos = x[n].id;
    for (int i = n - 1; i >= 1; i--) {
      if (x[i].id > mpos) {
        ans++;
        mpos = x[i].id;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
