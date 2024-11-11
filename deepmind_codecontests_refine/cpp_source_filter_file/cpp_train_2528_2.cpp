#include <bits/stdc++.h>
using namespace std;
struct node {
  int x;
  int y;
  int k;
  bool operator<(const node &z) const { x < z.x; }
} men[100010];
int ans[100010];
int main() {
  int n;
  int m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> men[i].x;
    cin >> men[i].y;
    men[i].y = n - men[i].y + 1;
    men[i].k = i;
  }
  sort(men + 1, men + m + 1);
  set<int> s;
  for (int i = 1; i <= n; i++) s.insert(i);
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    set<int>::iterator it = s.lower_bound(men[i].y);
    if (it != s.end() && *it <= men[i].x) {
      s.erase(it);
      ans[++cnt] = men[i].k;
    }
  }
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
