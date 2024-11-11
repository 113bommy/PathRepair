#include <bits/stdc++.h>
using namespace std;
int a[1000007];
char s[1000007];
int v[1000007];
int main() {
  gets(s);
  int la = strlen(s);
  v[0] = 1;
  int count = 1;
  int jia = 1;
  int jian = 0;
  int i;
  for (i = 1; i < la; i++) {
    if (s[i] == '+') {
      v[count++] = 1;
      jia++;
    } else if (s[i] == '-') {
      v[count++] = -1;
      jian++;
    }
    if (s[i] == '=') break;
  }
  int n = 0;
  for (; i < la; i++) {
    if (s[i] >= '0' && s[i] <= '9') n = n * 10 + s[i] - '0';
  }
  int sum = jia - jian;
  for (int i = 0; i < count; i++) a[i] = 1;
  for (int i = 0; i < count; i++) {
    while (sum < n && a[i] < n && v[i] == 1) {
      a[i]++;
      sum++;
    }
    while (sum > n && a[i] < n && v[i] == -1) {
      a[i]--;
      sum--;
    }
  }
  if (sum != n)
    printf("Impossible\n");
  else {
    printf("Possible\n");
    printf("%d", a[0]);
    for (int i = 1; i < count; i++) {
      if (v[i] > 0)
        printf("+%d", a[i]);
      else
        printf("-%d", a[i]);
    }
    printf("==%d\n", n);
  }
}
