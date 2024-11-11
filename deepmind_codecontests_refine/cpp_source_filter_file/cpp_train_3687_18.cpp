#include <bits/stdc++.h>
using namespace std;
int arr[100010];
vector<int> v;
int main(void) {
  int n, k, i, j, totalcnt;
  scanf("%d %d", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    v.push_back(arr[i]);
    ;
  }
  if (k == 1) {
    sort(v.begin(), v.end());
    printf("%d\n", v[0]);
  } else {
    int cnt = 0, sum = 0, mn = (1 << 29), indx, flag = 0;
    totalcnt = 0;
    for (i = 1; i <= n; i++) {
      sum = 0;
      cnt = 0;
      for (j = i;; j += k) {
        if (j > n) j %= n;
        sum += arr[j];
        totalcnt++;
        cnt++;
        if (cnt == (n / k)) {
          break;
        }
      }
      if (mn > sum) {
        indx = i;
        mn = sum;
      }
      if (totalcnt == n) break;
    }
    printf("%d\n", indx);
  }
  return 0;
}
