#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
struct shuzu {
  long x;
  long y;
  long z;
  long num;
};
shuzu a[maxn];
bool cmp(shuzu a, shuzu b) {
  if (a.x != b.x) return a.x > b.x;
  if (a.y != b.y) return a.y > b.y;
  return a.z > b.z;
}
void swap(long& a, long& b) {
  long t = b;
  b = a;
  a = t;
}
int main() {
  long n;
  long max = 0;
  long temp;
  long ans1, ans2;
  scanf("%ld", &n);
  for (long i = 0; i < n; i++) {
    long x, y, z;
    scanf("%ld%ld%ld", &x, &y, &z);
    if (x < y) swap(x, y);
    if (x < z) swap(x, z);
    if (y < z) swap(y, z);
    a[i].x = x;
    a[i].y = y;
    a[i].z = z;
    a[i].num = i + 1;
  }
  sort(a, a + n, cmp);
  temp = 0;
  max = a[0].z;
  ans1 = 0;
  ans2 = 0;
  for (long i = 1; i < n; i++) {
    if (a[temp].x == a[i].x && a[temp].y == a[i].y) {
      long tempmax = a[temp].z + a[i].z;
      if (tempmax < a[temp].y) tempmax = a[temp].y;
      if (max < tempmax) {
        max = tempmax;
        ans1 = temp;
        ans2 = i;
      }
    } else {
      temp = i;
      if (max < a[i].z) {
        max = a[i].z;
        ans1 = ans2 = i;
      }
    }
  }
  ans1 = a[ans1].num;
  ans2 = a[ans2].num;
  if (ans1 == ans2)
    printf("1\n%ld\n", ans1);
  else {
    if (ans1 > ans2) swap(ans1, ans2);
    printf("2\n%ld %ld\n", ans1, ans2);
  }
  return 0;
}
