#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
char str[MAX], ans[MAX * 10];
int main() {
  int n, m;
  int num = 0, num1 = 0, num2 = 0;
  int ant = 1;
  scanf("%d%d", &n, &m);
  scanf("%s", str);
  for (int i = 1; i <= n; i++) {
    if (str[i] == '(') {
      if (num1 <= (m / 2)) {
        printf("(");
        num1++;
      }
    } else {
      if (num2 < num1) {
        printf(")");
        num2++;
      }
    }
  }
  return 0;
}
