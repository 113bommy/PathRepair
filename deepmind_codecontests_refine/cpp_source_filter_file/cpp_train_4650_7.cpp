#include <bits/stdc++.h>
using namespace std;
struct node {
  int a;
  int b;
  int x;
} num[1009];
bool cmp(node a, node b) { return a.x > b.x; }
int main() {
  long long ans = 0;
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  for (int i = 1; i <= n; i++) cin >> num[i].a;
  for (int i = 1; i <= n; i++) {
    cin >> num[i].b;
    num[i].x = fabs(num[i].a - num[i].b);
  }
  sort(num + 1, num + n + 1, cmp);
  for (int i = 1; i <= k1 + k2; i++) {
    if (num[1].x == 0)
      num[1].x++;
    else
      num[1].x--;
    sort(num + 1, num + n + 1, cmp);
  }
  for (int i = 1; i <= n; i++) {
    ans = ans + num[i].x * num[i].x;
  }
  cout << ans << endl;
  return 0;
}
