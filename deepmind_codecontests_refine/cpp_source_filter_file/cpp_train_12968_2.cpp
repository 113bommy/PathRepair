#include <bits/stdc++.h>
using namespace std;
int main() {
  char puzzel[100];
  vector<string> Puz;
  int m, n;
  int stp;
  int len = 0, judge = 0;
  int prevstp;
  int prevlen;
  int minv = 1000;
  int maxv = -9;
  int flag = 0;
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; i++) {
    scanf("%s", puzzel);
    Puz.push_back(puzzel);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (puzzel[j] == 'X') {
        stp = j;
        len++;
        for (int k = j; k < n - 1; k++) {
          if (puzzel[k + 1] == 'X') {
            len++;
          } else {
            break;
          }
        }
        if (flag == 0) {
          flag = 1;
          prevlen = len;
          prevstp = stp;
          len = 0;
        } else {
          if (prevstp == stp && prevlen == len) {
            prevstp = stp;
            prevlen = len;
            len = 0;
          } else {
            judge = 1;
          }
        }
        break;
      }
    }
  }
  if (judge == 1) {
    printf("NO\n");
  } else if (flag == 1) {
    printf("YES\n");
  }
  return 0;
}
