#include <bits/stdc++.h>
using namespace std;
struct NN {
  int x, r;
  int id;
};
NN ss[10100];
int num[10100];
bool cmp(const NN &cmp1, const NN &cmp2) { return cmp1.x < cmp2.x; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &ss[i].x, &ss[i].r);
    ss[i].id = i;
  }
  sort(ss, ss + n, cmp);
  memset(num, -1, sizeof(num));
  int m;
  scanf("%d", &m);
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (ss[mid].x <= x) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    int posi = l - 1;
    for (int j = 0; j < 2; j++) {
      if (posi >= 0 && posi < n) {
        if ((long long)(x - ss[posi].x) * (x - ss[posi].x) + (long long)y * y -
                (long long)ss[posi].r * ss[posi].r <=
            0)
          if (num[ss[posi].id] == -1) {
            num[ss[posi].id] = i + 1;
            cnt++;
          }
      }
      posi++;
    }
  }
  printf("%d\n", cnt);
  for (int i = 0; i < n; i++) {
    printf("%d", num[i]);
    if (i != n - 1) printf(" ");
  }
  printf("\n");
  return 0;
}
