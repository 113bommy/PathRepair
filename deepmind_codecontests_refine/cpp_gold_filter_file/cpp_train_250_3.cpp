#include <bits/stdc++.h>
using namespace std;
const int maxn = 201;
int n, m;
int a[maxn];
int ca[maxn], cb[maxn];
int ans = 0;
bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) {
      int temp = 0;
      memset(ca, 0, sizeof(ca));
      memset(cb, 0, sizeof(cb));
      int l1 = 0;
      int l2 = 0;
      for (int k = 1; k <= n; k++) {
        if (k >= j && k <= i)
          ca[++l1] = a[k];
        else
          cb[++l2] = a[k];
      }
      sort(ca + 1, ca + 1 + l1, cmp2);
      sort(cb + 1, cb + 1 + l2, cmp2);
      int now = m;
      int s1 = 1;
      int s2 = 1;
      for (int k = 1; k <= i - j + 1; k++) {
        if (now && s2 <= l2) {
          if (ca[s1] >= cb[s2])
            temp += ca[s1++];
          else
            temp += cb[s2++], now--;
        } else
          temp += ca[s1++];
      }
      if (i == 1 && j == 1)
        ans = temp;
      else
        ans = max(ans, temp);
    }
  printf("%d", ans);
  return 0;
}
