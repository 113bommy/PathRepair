#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3;
string s;
int num1, num2;
int sum1, sum2;
int s1[MAXN + 1], s2[MAXN + 1];
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (i <= 2) {
      num1++;
      s1[num1] = s[i] - '0';
      sum1 += s1[num1];
    } else {
      num1++;
      s1[num1] = s[i] - '0';
      sum2 += s1[num1];
    }
  }
  if (sum1 == sum2) {
    printf("0\n");
    return 0;
  }
  if (sum1 < sum2) {
    for (int i = 1; i <= 3; i++) {
      s1[i] = 9 - s1[i];
    }
    for (int i = 4; i <= 6; i++) {
      s1[i] = s1[i] - 0;
    }
  } else {
    for (int i = 1; i <= 3; i++) {
      s1[i] = s1[i];
    }
    for (int i = 4; i <= 6; i++) {
      s1[i] = 9 - s1[i];
    }
  }
  sort(s1 + 1, s1 + 1 + 6);
  int sum = abs(sum1 - sum2);
  int i;
  for (i = 6; i >= 1; i--) {
    sum -= s1[i];
    if (sum <= 0) break;
  }
  printf("%d\n", 6 - i + 1);
  return 0;
}
