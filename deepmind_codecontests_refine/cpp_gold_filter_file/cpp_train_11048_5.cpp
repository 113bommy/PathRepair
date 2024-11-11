#include <bits/stdc++.h>
using namespace std;
struct node {
  int x;
  int y;
} a[1005], mov[1005];
bool cmp(const node &a, const node &b) {
  if (a.x != b.x)
    return a.x < b.x;
  else
    return a.y < b.y;
}
bool cmp2(const node &a, const node &b) {
  if (a.x != b.x)
    return a.x > b.x;
  else
    return a.y > b.y;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].x, &a[i].y);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &mov[i].x, &mov[i].y);
  }
  sort(a + 1, a + 1 + n, cmp);
  sort(mov + 1, mov + 1 + n, cmp2);
  int ansx;
  int ansy;
  ansx = a[1].x + mov[1].x;
  ansy = a[1].y + mov[1].y;
  bool able = true;
  printf("%d %d", ansx, ansy);
}
