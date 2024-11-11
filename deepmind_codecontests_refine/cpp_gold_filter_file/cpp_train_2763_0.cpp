#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, flag = 0, flag1 = 0, flag2 = 0, flag3 = 0;
  string x, y;
  cin >> n >> x, y = x;
  for (long long i = 0; i < n; i++)
    if (y[i] > '3')
      y[i] -= 3;
    else if (y[i] == '0')
      y[i] = '8';
    else {
      flag = 1;
      goto down;
    }
down:
  printf("");
  if (!flag) return 0 * printf("NO\n");
  y = x;
  for (long long i = 0; i < n; i++)
    if (y[i] == '7' || y[i] == '9' || y[i] == '0') {
      flag1 = 1;
      goto down1;
    } else if (y[i] != '8')
      y[i] += 3;
    else
      y[i] = '0';
down1:
  printf("");
  if (!flag1) return 0 * printf("NO\n");
  y = x;
  for (long long i = 0; i < n; i++)
    if (y[i] == '3' || y[i] == '6' || y[i] == '9' || y[i] == '0') {
      flag2 = 1;
      goto down2;
    } else
      y[i]++;
down2:
  printf("");
  if (!flag2) return 0 * printf("NO\n");
  y = x;
  for (long long i = 0; i < n; i++)
    if (y[i] == '1' || y[i] == '4' || y[i] == '7' || y[i] == '0') {
      flag3 = 1;
      goto down3;
    } else
      y[i]--;
down3:
  printf("");
  if (!flag3) return 0 * printf("NO\n");
  return 0 * printf("YES\n");
}
