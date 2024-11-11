#include <bits/stdc++.h>
using namespace std;
char str[1000007];
int f[1000007], l[1000007];
int Ans[1000007];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", str + 1);
  f[0] = -1;
  for (int i = 1; i <= n; i++) {
    int j = f[i - 1];
    while (j >= 0 && str[j + 1] != str[i]) j = f[j];
    f[i] = j + 1;
  }
  for (int i = 1; i <= n; i++) {
    l[i] = i - f[i];
    int d = i / l[i], r = i % l[i];
    if (((r && d / k > d % k) || (!r && (d / k >= d % k))))
      printf("1");
    else
      printf("0");
  }
}
