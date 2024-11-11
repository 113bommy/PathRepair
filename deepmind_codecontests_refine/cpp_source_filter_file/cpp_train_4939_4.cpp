#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int MinChange(int a[][100], int n, int m, int k) {
    if (n <= k) {
      int ans = 1e9;
      for (int t = 0; t < (1 << n); t++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
          int bit = 0;
          for (int j = 0; j < n; j++) bit += (a[j][i] << j);
          sum += min(BitNum(t ^ bit), BitNum(t ^ ((1 << k) - 1 - bit)));
        }
        ans = min(sum, ans);
      }
      if (ans > k)
        return -1;
      else
        return ans;
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < n; j++)
        if (i != j) {
          int f0 = 0, f1 = 0;
          if (a[j][0] == 0)
            f1++;
          else
            f0++;
          for (int k = 1; k < m; k++)
            if (a[i][0] == a[i][k]) {
              if (a[j][k] == 0)
                f1++;
              else
                f0++;
            } else {
              if (a[j][k] == 0)
                f0++;
              else
                f1++;
            }
          sum += min(f0, f1);
        }
      ans = min(ans, sum);
    }
    if (ans > k) return -1;
    return ans;
  }

 private:
  int BitNum(int num) {
    int ans = 0;
    while (num) {
      ans += (num & 1);
      num >>= 1;
    }
    return ans;
  }
};
int a[100][100];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  Solution ans;
  printf("%d\n", ans.MinChange(a, n, m, k));
  return 0;
}
