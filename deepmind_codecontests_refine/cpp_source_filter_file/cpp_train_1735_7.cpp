#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = (int)2e5 + 5;
int n, pos;
struct node {
  int x;
  int y;
  long long num;
} a[200];
bool cmp(node a, node b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y > b.y;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i].num);
    int temp = a[i].num;
    while (temp % 2 == 0) {
      temp /= 2;
      a[i].x++;
    }
    while (temp % 3 == 0) {
      temp /= 3;
      a[i].y++;
    }
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) printf("%lld ", a[i].num);
  return 0;
}
