#include <bits/stdc++.h>
using namespace std;
int const maxsize = 10e5 + 10;
int n;
int num[maxsize << 1];
int sum[3][maxsize << 1];
struct ANS {
  int a, b;
};
ANS ans[maxsize];
int winner;
bool cmp(ANS i, ANS j) { return i.a < i.b; }
int main() {
  while (cin >> n) {
    for (int t = 1; t <= n; t++) {
      int k;
      scanf("%d", &k);
      sum[k][t] = sum[k][t - 1] + 1;
      sum[3 - k][t] = sum[3 - k][t - 1];
      if (t == n) winner = k;
    }
    for (int t = n + 1; t <= (n << 1); t++) {
      sum[winner][t] = sum[winner][t - 1] + 1;
    }
    int l = 0;
    for (int i = 1; i <= n; i++) {
      int k[3];
      k[1] = k[2] = 0;
      int j = 1;
      for (; j <= n;) {
        int low = j, high = j + (i << 1), mid;
        while (low < high) {
          mid = ((low + high) >> 1);
          if ((sum[1][mid] - sum[1][j - 1]) > i ||
              (sum[2][mid] - sum[2][j - 1]) > i)
            high = mid - 1;
          if ((sum[1][mid] - sum[1][j - 1]) >= i ||
              (sum[2][mid] - sum[2][j - 1]) >= i)
            high = mid;
          if ((sum[1][mid] - sum[1][j - 1]) < i &&
              (sum[2][mid] - sum[2][j - 1]) < i)
            low = mid + 1;
        }
        if (sum[1][low] - sum[1][j - 1] == i)
          k[1]++;
        else if (sum[2][low] - sum[2][j - 1] == i)
          k[2]++;
        j = low + 1;
      }
      if (j > n) {
        if (j == n + 1 && k[winner] > k[3 - winner]) {
          l++;
          ans[l].b = i;
          ans[l].a = k[winner];
        }
      }
    }
    sort(ans + 1, ans + 1 + l, cmp);
    printf("%d\n", l);
    for (int t = 1; t <= l; t++) {
      printf("%d %d\n", ans[t].a, ans[t].b);
    }
  }
  return 0;
}
