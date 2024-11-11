#include <bits/stdc++.h>
using namespace std;
int m, n, len, month, day, hour, minute, second, sum[15], a[5000005];
char s[5000005];
const int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  scanf("%d%d", &n, &m);
  gets(s);
  for (int i = 2; i <= 12; i++) sum[i] = sum[i - 1] + days[i - 1];
  while (gets(s)) {
    sscanf(s, "2012-%d-%d %d:%d:%d:", &month, &day, &hour, &minute, &second);
    a[++len] = (sum[month] + day) * 86400 + hour * 3600 + minute * 60 + second;
    if (len - m + 1 >= 1 && a[len] - a[len - m + 1] < n) {
      printf("2012-%02d-%02d %02d:%02d:%02d\n", month, day, hour, minute,
             second);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
