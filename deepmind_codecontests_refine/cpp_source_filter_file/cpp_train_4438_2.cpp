#include <bits/stdc++.h>
using namespace std;
map<long long, int> Map;
long long power[15];
int n;
char str[70010][15];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", str[i] + 1);
  power[1] = 1;
  for (int i = 2; i <= 9; i++) power[i] = power[i - 1] * 11;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 9; j++) {
      long long num = 0;
      for (int k = j; k <= 9; k++) {
        num = num * 11 + str[i][k] - '0' + 1;
        Map[num]++;
      }
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 9; j++) {
      long long num = 0;
      for (int k = 1; k <= j; k++) num = num * 11 + str[i][k] - '0' + 1;
      Map[num]--;
      for (int k = j + 1; k <= 9; k++) {
        num = (num - power[j] * (str[i][k - j] - '0' + 1)) * 11 + str[i][k] -
              '0' + 1;
        Map[num]--;
      }
    }
    for (int j = 1; j <= 9; j++) {
      long long num = 0;
      for (int k = 1; k <= j; k++) num = num * 11 + str[i][k] - '0' + 1;
      if (Map[num] == 0) {
        for (int k = 1; k <= j; k++) printf("%c", str[i][k]);
        printf("\n");
        goto Continue;
      }
      for (int k = j + 1; k <= 9; k++) {
        num = (num - power[j] * (str[i][k - j] - '0' + 1)) * 11 + str[i][k] -
              '0' + 1;
        if (Map[num] == 0) {
          for (int l = k - j + 1; l <= k; l++) printf("%c", str[i][l]);
          printf("\n");
          goto Continue;
        }
      }
    }
  Continue:;
    for (int j = 1; j <= 9; j++) {
      long long num = 0;
      for (int k = 1; k <= j; k++) num = num * 11 + str[i][k] - '0' + 1;
      Map[num]--;
      for (int k = j + 1; k <= 9; k++) {
        num = (num - power[j] * (str[i][k - j] - '0' + 1)) * 11 + str[i][k] -
              '0' + 1;
        Map[num]++;
      }
    }
  }
  return 0;
}
