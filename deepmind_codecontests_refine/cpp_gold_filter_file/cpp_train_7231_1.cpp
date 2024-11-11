#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y, z, id;
  bool operator<(const point &a) const { return y > a.y; }
} a[100010], b[100010];
struct cmp {
  bool operator()(const point &a, const point &b) const {
    if (a.x == b.x) return a.id < b.id;
    return a.x > b.x;
  }
};
set<point, cmp> s;
set<point>::iterator it;
int ans[100010];
int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].id = i + 1;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i].x >> b[i].y >> b[i].z;
    b[i].id = i + 1;
  }
  sort(a, a + n);
  sort(b, b + m);
  int fr = 0;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    for (int j = fr; j < m; j++, fr++) {
      if (b[j].y >= a[i].y)
        s.insert(b[j]);
      else
        break;
    }
    int id = a[i].id;
    a[i].id = -1;
    it = s.lower_bound(a[i]);
    if (it == s.end()) {
      flag = false;
      break;
    } else {
      point tmp = *it;
      ans[id] = it->id;
      s.erase(it);
      if (--tmp.z) s.insert(tmp);
    }
  }
  if (flag) {
    puts("YES");
    cout << ans[1];
    for (int i = 2; i <= n; i++) cout << " " << ans[i];
    cout << endl;
  } else
    puts("NO");
  return 0;
}
