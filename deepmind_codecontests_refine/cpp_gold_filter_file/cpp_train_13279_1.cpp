#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
string kk[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};
string ss[6] = {"S,M", "M,L", "L,XL", "XL,XXL", "XXL,XXXL"};
string t[MAXN];
int main() {
  int n, i, j;
  int sum[7] = {0};
  for (i = 0; i < 6; i++) scanf("%d", sum + i);
  bool flag = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> t[i];
    for (j = 0; j < 6; j++)
      if (t[i] == kk[j]) {
        sum[j]--;
        if (sum[j] < 0) flag = 1;
      }
  }
  if (flag) {
    printf("NO\n");
    return 0;
  }
  for (i = 0; i < 5; i++)
    for (j = 0; j < n; j++) {
      if (t[j] == ss[i]) {
        if (sum[i] > 0) {
          sum[i]--;
          t[j] = kk[i];
          continue;
        }
        if (sum[i + 1] > 0) {
          sum[i + 1]--;
          t[j] = kk[i + 1];
          continue;
        }
        flag = 1;
        break;
      }
    }
  if (flag) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  for (i = 0; i < n; i++) cout << t[i] << endl;
  return 0;
}
