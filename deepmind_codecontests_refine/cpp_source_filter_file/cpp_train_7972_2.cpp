#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
struct node {
  int x, y, i;
  bool operator<(const node t) const {
    if (x == t.x) {
      return y == t.y ? i < t.i : y > t.y;
    }
    return x > t.x;
  }
} a[maxn];
vector<int> ans;
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x, a[i].i = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].y;
  }
  sort(a, a + n + 1);
  ans.push_back(a[0].i);
  for (int i = 1; i < n; i += 2) {
    if (i + 1 < n || a[i].y < a[i + 1].y)
      ans.push_back(a[i + 1].i);
    else
      ans.push_back(a[i].i);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  return 0;
}
