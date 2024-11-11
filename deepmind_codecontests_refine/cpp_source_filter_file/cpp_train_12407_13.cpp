#include <bits/stdc++.h>
int lamp[100][200];
int checkLight(char a[], int n) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1') cnt++;
  }
  return cnt;
}
int main() {
  int n;
  scanf("%d", &n);
  char s[101];
  scanf("%s", s);
  int initOn = checkLight(s, n);
  int a, b;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    int bOn = s[i] - '0';
    for (int j = 0; j < 1000; j++) {
      if (j < b) {
        lamp[i][j] = bOn;
        continue;
      } else if ((j - b) % a == 0)
        bOn = (bOn + 1) % 2;
      lamp[i][j] = bOn;
    }
  }
  int ans = initOn;
  for (int i = 0; i < 1000; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (lamp[j][i] == 1) cnt++;
    }
    ans = ((ans) > (cnt) ? (ans) : (cnt));
  }
  printf("%d\n", ans);
}
