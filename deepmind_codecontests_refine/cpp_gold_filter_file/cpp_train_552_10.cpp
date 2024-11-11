#include <bits/stdc++.h>
using namespace ::std;
struct pairs {
  int x;
  int y;
};
bool comp(struct pairs a, struct pairs b) {
  return (a.x > b.x || (a.x == b.x && a.y < b.y));
}
int main() {
  int n, k;
  cin >> n >> k;
  struct pairs a[55];
  for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
  sort(a, a + n, comp);
  int x = a[k - 1].x, y = a[k - 1].y;
  int counter = 0;
  for (int i = 0; i < n; i++)
    if (a[i].x == x && a[i].y == y) counter++;
  cout << counter << endl;
  return 0;
}
