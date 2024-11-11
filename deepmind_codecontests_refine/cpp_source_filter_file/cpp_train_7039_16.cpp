#include <bits/stdc++.h>
using namespace std;
long long lower, upper, res;
char num1[65536], num2[65536], num[65536];
void DFS(int depth, bool lower_flag, bool upper_flag) {
  if (depth == 9) {
    long long a = 0, b = 0;
    bool flag = false;
    for (int i = 0; i < 9; i++) {
      if (num[i] != '0') {
        flag = true;
      }
      if (flag) {
        a = a * 10 + num[i] - '0';
        b = b * 10 + 9 - (num[i] - '0');
      }
    }
    if (lower <= a && a <= upper) {
      res = max(res, a * b);
    }
    return;
  }
  char a, b;
  if (lower_flag && upper_flag) {
    a = min(num1[depth], num2[depth]);
    b = max(num1[depth], num2[depth]);
  } else if (lower_flag) {
    a = num1[depth];
    b = '9';
  } else if (upper_flag) {
    a = '0';
    b = num2[depth];
  } else {
    a = '0';
    b = '9';
  }
  if (a <= '4' && '4' <= b) {
    num[depth] = '4';
    DFS(depth + 1, lower_flag && num1[depth] == '4',
        upper_flag && num2[depth] == '4');
  }
  if (a <= '5' && '5' <= b) {
    num[depth] = '5';
    DFS(depth + 1, lower_flag && num1[depth] == '5',
        upper_flag && num2[depth] == '5');
  }
  num[depth] = a;
  DFS(depth + 1, lower_flag && num1[depth] == a,
      upper_flag && num2[depth] == a);
  num[depth] = b;
  DFS(depth + 1, lower_flag && num1[depth] == b,
      upper_flag && num2[depth] == b);
}
int main() {
  scanf("%lld%lld", &lower, &upper);
  sprintf(num1, "%09lld", lower);
  sprintf(num2, "%09lld", upper);
  DFS(0, true, true);
  printf("%lld\n", res);
  return 0;
}
