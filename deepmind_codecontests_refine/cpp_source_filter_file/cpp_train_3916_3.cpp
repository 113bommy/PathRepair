#include <bits/stdc++.h>
using namespace std;
long long n, k, m;
long long s2, s4, s1;
long long a[110];
long long er = 2;
bool cmp(int aa, int bb) { return aa > bb; }
int main() {
  scanf("%d%d", &n, &k);
  s2 = n * 2;
  s4 = n;
  for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
  sort(a + 1, a + k + 1, cmp);
  for (int i = 1; i <= k; i++) {
    if (a[i] >= 4) {
      m = min(a[i] / 4, s4);
      s4 -= m;
      a[i] -= (m * 4);
    }
    if (a[i] == 3) {
      if (s4 > 0) {
        s4 -= 1;
        a[i] -= 3;
      }
    }
    if (a[i] >= 2) {
      m = min((a[i]) / 2, s2);
      s2 -= m;
      a[i] -= m * 2;
    }
    if (a[i] > 0) {
      if (s1 > 0 && a[i] == 1) {
        while (s1 > 0 && a[i] > 0) {
          a[i]--;
          s1--;
        }
      }
      if (a[i] == 0) continue;
      if (s4 > 0) {
        if (a[i] == 2) {
          s4--;
          s1++;
          a[i] = 0;
        } else if (a[i] == 1) {
          s4--;
          s1++;
          a[i]--;
        }
      }
      if (s2 > 0 && a[i] > 0) {
        s2--;
        m = min(a[i], er);
        a[i] = a[i] - m;
      }
      if (a[i] > 0 && s1 > 0) {
        while (a[i] && s1) {
          s1--;
          a[i]--;
        }
      }
      if (a[i] <= 0) continue;
      printf("NO");
      return 0;
    }
  }
  printf("YES");
  return 0;
}
