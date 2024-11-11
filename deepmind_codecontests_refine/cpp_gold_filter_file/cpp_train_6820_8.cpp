#include <bits/stdc++.h>
using ld = long double;
using namespace std;
const double eps = (1e-11);
const long long INF = 2e9 + 9;
const int logn = 21;
const double pi = acos(-1.0);
int pp = 119;
int cri[300005];
int nums[10];
int tong[10];
int main() {
  int n;
  scanf("%d", &n);
  int a, b, c;
  int ty = 0;
  scanf("%d%d%d", &nums[1], &nums[0], &nums[2]);
  sort(nums, nums + 3);
  a = nums[0];
  b = nums[1];
  c = nums[2];
  for (int i = 0; i < n; i++) {
    scanf("%d", &cri[i]);
  }
  sort(cri, cri + n);
  nums[3] = a + b;
  nums[4] = a + c;
  nums[5] = b + c;
  nums[6] = a + b + c;
  nums[7] = INF;
  if (nums[3] > nums[2])
    ty = 1;
  else
    ty = 0, swap(nums[3], nums[2]);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    while (cri[i] > nums[cnt]) cnt++;
    tong[cnt]++;
  }
  if (tong[7] > 0) {
    printf("-1\n");
  } else {
    int ans = tong[6];
    ans += tong[5];
    tong[0] -= tong[5];
    tong[0] = max(tong[0], 0);
    ans += tong[4];
    tong[1] -= tong[4];
    if (tong[1] < 0) {
      tong[0] += tong[1];
      tong[1] = 0;
      tong[0] = max(tong[0], 0);
    }
    if (a + b <= c) {
      for (int cc = tong[3]; cc <= n; cc++) {
        int tmp2 = cc - tong[3];
        int tmp1 = tong[1];
        int tmp0 = tong[0];
        tmp2 = tong[2] - tmp2;
        if (tmp2 < 0) {
          tmp1 += tmp2;
          if (tmp1 < 0) {
            tmp0 += tmp1;
            tmp1 = 0;
            tmp0 = max(tmp0, 0);
          }
          tmp2 = 0;
        }
        int lst = cc;
        lst -= tmp2;
        if (tmp1 <= lst && (tmp1 + tmp0 + 1) / 2 <= lst) {
          ans += cc;
          break;
        }
      }
    } else if (a + b > c) {
      int tmp = min(tong[2], tong[3]);
      ans += tmp;
      tong[2] -= tmp;
      tong[3] -= tmp;
      if (tong[3] > 0) {
        int lst = 0;
        lst = (tong[3] + tong[2]);
        ans += lst;
        tong[1] -= lst;
        if (tong[1] < 0) {
          tong[0] += tong[1];
          tong[1] = 0;
          tong[0] = max(tong[0], 0);
        }
        lst = (tong[1] + 1) / 2;
        lst = max(lst, (tong[1] + tong[0] + 2) / 3);
        ans += lst;
      } else {
        for (int cc = 0; cc <= n; cc++) {
          if (cc < tong[2]) {
            int val = 2 * cc - tong[2];
            if (val < 0)
              continue;
            else {
              if (tong[1] <= val && (tong[1] + tong[0] + 1) / 2 <= val) {
                ans += cc;
                break;
              }
            }
          } else {
            int tmp2 = cc - tong[2];
            int tmp1 = tong[1];
            int tmp0 = tong[0];
            tmp1 -= tmp2;
            if (tmp1 < 0) {
              tmp0 += tmp1;
              tmp1 = 0;
              tmp0 = max(tmp0, 0);
            }
            tmp2 = 0;
            int lst = cc;
            if (tmp1 <= lst && (tmp1 + tmp0 + 1) / 2 <= lst) {
              ans += cc;
              break;
            }
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
