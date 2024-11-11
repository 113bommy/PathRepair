#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
} a[200005];
bool cmp(struct point A, struct point B) {
  if (A.x != B.x) return A.x < B.x;
  return A.y < B.y;
}
int m;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].x);
    a[i].y = i + 1;
  }
  int num = 0;
  for (int i = n; i < 2 * n; i++) {
    scanf("%d", &a[i].x);
    a[i].y = i + 1 - n;
    if (a[i].x == a[i - n].x) num++;
  }
  n *= 2;
  a[n].x = 1e9 + 1;
  n++;
  sort(a, a + n, cmp);
  cin >> m;
  long long ans = 1;
  int count = 1;
  for (int i = 1; i < n; i++) {
    if (a[i].x == a[i - 1].x) {
      count++;
      ans = (ans * count);
      while (num && ans % 2 == 0) {
        ans /= 2;
        num--;
      }
      ans %= m;
    } else
      count = 1;
  }
  cout << ans << endl;
  return 0;
}
