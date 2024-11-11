#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * (1e5) + 5;
int temp[maxn];
int sumd[maxn];
int main() {
  int n, k, ans;
  scanf("%d%d", &n, &k);
  int cnt = 0;
  memset(sumd, 0, sizeof(sumd));
  int st = n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp[i]);
    if (temp[i] < 0) {
      cnt++;
      if (st == n) st = i;
    }
  }
  if (cnt > k)
    printf("-1\n");
  else if (cnt == k)
    printf("1\n");
  else {
    int count1 = 2 * cnt;
    if (temp[n - 1] < 0) count1--;
    ans = -1;
    bool flag = 0;
    for (int i = st; i < n; i++) {
      if (temp[i] < 0) {
        if (!flag)
          flag = 1;
        else {
          count1 -= 2;
        }
        k--;
      } else {
        if (flag) ans++;
        sumd[ans]++;
        flag = 0;
      }
    }
    if (temp[n - 1] < 0) ans++;
    sort(sumd, sumd + ans);
    for (int i = 0; i < ans; i++) {
      if (k >= sumd[i] && k > 0) {
        k -= sumd[i];
        count1 -= 2;
      } else
        break;
    }
    if (temp[n - 1] >= 0) {
      if (k >= sumd[ans]) count1--;
    }
    printf("%d\n", count1);
  }
}
