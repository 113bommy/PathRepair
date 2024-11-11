#include <bits/stdc++.h>
using namespace std;
int mxof(int x) {
  int mx = 0;
  while (x) {
    mx = max(mx, x % 10);
    x /= 10;
  }
  return mx;
}
int getone(int n) {
  int cnt = 0;
  while (n) {
    n -= mxof(n);
    cnt++;
  }
  return cnt;
}
int downto[10][1000000];
int cirno[10][1000000];
int mxx[1000010];
int main(void) {
  for (int i = 0; i <= 1000000; i++) mxx[i] = mxof(i);
  for (int i = 0; i < 10; i++) {
    for (int j = 1; j < 1000000; j++) {
      int tmi = mxx[j];
      if (j - tmi < 0) {
        downto[i][j] = j - tmi;
        cirno[i][j] = 1;
      } else {
        downto[i][j] = downto[i][j - tmi];
        cirno[i][j] = cirno[i][j - tmi] + 1;
      }
      if (i) {
        tmi = i;
        if (j - tmi < 0) {
          downto[i][j] = min(downto[i][j], j - tmi);
          cirno[i][j] = 1;
        } else {
          if (cirno[i][j - tmi] + 1 < cirno[i][j] ||
              (cirno[i][j] == cirno[i][j - tmi] + 1 &&
               downto[i][j - tmi] < downto[i][j])) {
            downto[i][j] = downto[i][j - tmi];
            cirno[i][j] = cirno[i][j - tmi] + 1;
          }
        }
      }
    }
  }
  long long n = 0;
  scanf("%I64d", &n);
  long long ans = 0;
  if (n < 2000000) {
    ans = getone(n);
  } else {
    int n1 = n / 1000000;
    int n2 = n % 1000000;
    while (n1) {
      ans += cirno[mxx[n1]][n2];
      n2 = 1000000 + downto[mxx[n1]][n2];
      if (n2 == 1000000) {
        ans++;
        n2 -= mxx[n1];
      }
      n1--;
    }
    if (n2) ans += cirno[0][n2];
  }
  printf("%I64d\n", ans);
  while (getchar() != EOF)
    ;
  return 0;
}
