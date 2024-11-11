#include <bits/stdc++.h>
using namespace std;
const int N = 3000010;
long long s1, s2;
int n, n1, n2, num, t[N];
struct P {
  int s, id;
} a[N], a1[N], a2[N];
struct Q {
  int x, y, d;
} q[N];
bool operator<(const P &a, const P &b) { return a.s < b.s; }
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++)
    scanf("%d", &a[i].s), s1 += a[i].s, a[i].id = i;
  for (int i = (1); i <= (n); i++) scanf("%d", &t[i]), s2 += t[i];
  if (s1 != s2) {
    puts("NO");
    return 0;
  }
  sort(a + 1, a + n + 1);
  sort(t + 1, t + n + 1);
  for (int i = (1); i <= (n); i++) {
    if (a[i].s < t[i]) a1[++n1] = (P){t[i] - a[i].s, i};
    if (a[i].s > t[i]) a2[++n2] = (P){a[i].s - t[i], i};
  }
  int j = 1;
  for (int i = (1); i <= (n1); i++) {
    int s = a1[i].s;
    while (s) {
      if (a1[i].id > a2[j].id) {
        puts("NO");
        return 0;
      }
      if (s < a2[j].s)
        q[++num] = (Q){a[a1[i].id].id, a[a2[j].id].id, s}, a2[j].s -= s, s = 0;
      else
        q[++num] = (Q){a[a1[i].id].id, a[a2[j].id].id, a2[j].id}, s -= a2[j].s,
        j++;
    }
  }
  printf("YES\n%d\n", num);
  for (int i = (1); i <= (num); i++)
    printf("%d %d %d\n", q[i].x, q[i].y, q[i].d);
  return 0;
}
