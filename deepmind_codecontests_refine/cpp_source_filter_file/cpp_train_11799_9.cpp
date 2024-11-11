#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, a;
  bool operator<(const node &b) const { return x < b.x; }
} house[1005];
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &house[i].x, &house[i].a);
  }
  sort(house, house + n);
  int ans = 2;
  for (int i = 0; i < n - 1; i++) {
    int temp =
        2 * (house[i + 1].x - house[i + 1].x) - (house[i].a + house[i + 1].a);
    if (temp > t * 2)
      ans += 2;
    else if (temp == t * 2)
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}
