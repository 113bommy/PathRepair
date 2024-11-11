#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int INF = 1e9 + 7;
const int N = 1010;
const double pi = 3.1415926;
int main() {
  char str[100010];
  while (~scanf("%s", str)) {
    int len = strlen(str);
    int idx = 0, sum0 = 0, sum1 = 0;
    for (int i = 0; i < len; i++) {
      if (str[i] == '2') {
        idx = i;
        break;
      }
      if (str[i] == '1') sum1++;
      if (str[i] == '0') sum0++;
    }
    for (int i = 0; i < sum0; i++) printf("0");
    for (int i = 0; i < sum1; i++) printf("1");
    sum1 = 0;
    for (int i = idx; i < len; i++) {
      if (str[i] == '1') sum1++;
    }
    for (int i = 0; i < sum1; i++) printf("1");
    for (int i = idx; i < len; i++) {
      if (str[i] != '1') printf("%c", str[i]);
    }
    printf("\n");
  }
  return 0;
}
