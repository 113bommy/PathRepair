#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, id;
};
bool cmp(const node& n1, const node& n2) { return n1.x < n2.x; }
bool cmp2(const node& n1, const node& n2) { return n1.id < n2.id; }
int main() {
  int n, m;
  node a[105];
  int x, y;
  int i, j, k;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a[i].x;
    a[i].id = i;
  }
  for (i = 0; i < m; i++) cin >> x >> y;
  sort(a, a + n, cmp);
  for (i = 0; i < n; i++) a[i].y = (i % 2);
  sort(a, a + n, cmp2);
  for (i = 0; i < n; i++) {
    cout << a[i].y << " ";
  }
  return 0;
}
