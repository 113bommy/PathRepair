#include <bits/stdc++.h>
using namespace std;
int const nMax = 1e6 + 10;
double const eps = 1e-8;
char ss[nMax];
int num[20];
int num2[20];
int cc[10] = {1869, 1968, 1689, 6198, 1698, 1986, 1896, 1869};
int main() {
  gets(ss);
  memset(num, 0, sizeof(num));
  int n = strlen(ss);
  for (int i = 0; i < n; i++) num[ss[i] - '0']++;
  num[6]--;
  num[1]--;
  num[8]--;
  num[9]--;
  for (int i = 1; i <= 10; i++) num2[i] = num[i];
  int temp = 4;
  int x = 1;
  int mod = 1;
  for (int i = 1; i <= temp; i++) mod *= 10;
  int total = 0;
  while (x < 10) {
    if (num[x] == 0) {
      x++;
      continue;
    }
    total += ((x * mod) % 7);
    total %= 7;
    mod *= 10;
    mod %= 7;
    num[x]--;
  }
  for (int i = 9; i >= 1; i--) {
    while (num2[i]) {
      printf("%d", i);
      num2[i]--;
    }
  }
  cout << cc[7 - total];
  for (int i = 1; i <= num[0]; i++) printf("0");
  cout << endl;
}
