#include <bits/stdc++.h>
using namespace std;
char str[100];
char res[100];
void func1() {
  int i, flag = 0, n = 0;
  for (i = 0; i < strlen(str); i++) {
    if (flag) n = n * 10 + str[i] - 48;
    if (str[i] == 'C') flag = 1;
  }
  int k;
  if (n <= 26) {
    n -= 0;
    k = 1;
  } else if (n <= 702) {
    n -= 26;
    k = 2;
  } else if (n <= 18278) {
    n -= (26 + 26 * 26);
    k = 3;
  } else if (n <= 475254) {
    n -= (26 + 26 * 26 + 26 * 26 * 26);
    k = 4;
  } else {
    n -= (26 + 26 * 26 + 26 * 26 * 26 + 26 * 26 * 26 * 26);
    k = 5;
  }
  n -= 1;
  for (i = k - 1; i >= 0; i--) {
    res[i] = n % 26 + 1 + 64;
    n = n / 26;
  }
  res[k] = '\0';
  cout << res;
  for (i = 1; str[i] != 'C'; i++) {
    cout << str[i];
  }
  printf("\n");
}
void func2() {
  cout << "R";
  int i, n, ans = 1;
  for (n = 0;; n++)
    if (str[n] > '0' && str[n] < '9') break;
  for (i = n; i < strlen(str); i++) cout << str[i];
  cout << "C";
  if (n == 2)
    ans += 26;
  else if (n == 3)
    ans += 26 + 26 * 26;
  else if (n == 4)
    ans += 26 + 26 * 26 + 26 * 26 * 26;
  else if (n == 5)
    ans += 26 + 26 * 26 + 26 * 26 * 26 + 26 * 26 * 26 * 26;
  int power = 1;
  for (i = n - 1; i >= 0; i--) {
    ans += (str[i] - 65) * power;
    power *= 26;
  }
  cout << ans << "\n";
}
int main() {
  int t;
  scanf("%d", &t);
  getchar();
  while (t--) {
    scanf("%s", str);
    getchar();
    int i, flag = 1;
    for (i = 0; i < strlen(str); i++) {
      if (str[i] >= 'A' && str[i] <= 'Z' && flag == 0) {
        flag = 1;
        func1();
        break;
      } else if (str[i] >= '0' && str[i] <= '9')
        flag = 0;
    }
    if (!flag) func2();
  }
  return 0;
}
