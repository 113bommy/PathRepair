#include <bits/stdc++.h>
using namespace std;
int siz, num1, num2, num3, num4;
int main() {
  int result = 0;
  scanf("%d %d", &num1, &num2);
  for (int i = 0; i < num1; i++) {
    scanf("%d", &num3);
    result += num3;
  }
  result = abs(result);
  if (result == 0) {
    printf(0);
  } else {
    siz = result / num2;
    if (result % num2 > 0) {
      siz++;
    }
    printf("%d", siz);
  }
}
