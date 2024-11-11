#include <bits/stdc++.h>
using namespace std;
int cc(char a) {
  if (a == '0')
    return 0;
  else if (a == '1')
    return 1;
  else if (a == '2')
    return 2;
  else if (a == '3')
    return 3;
  else if (a == '4')
    return 4;
  else if (a == '5')
    return 5;
  else if (a == '6')
    return 6;
  else if (a == '7')
    return 7;
  else if (a == '8')
    return 8;
  else if (a == '9')
    return 9;
  else {
    return a - 'A' + 10;
  }
}
int power(int a, int b) {
  int res = 1;
  for (int i = 0; i < b; i++) {
    res *= a;
  }
  return res;
}
int main() {
  char buffer[100];
  gets(buffer);
  string A = "";
  string B = "";
  int sz = strlen(buffer);
  bool next = false;
  for (int i = 0; i < sz; i++) {
    if (buffer[i] != ':' && !next) {
      A += buffer[i];
    } else if (buffer[i] == ':') {
      next = true;
    } else if (next) {
      B += buffer[i];
    }
  }
  int asz = A.size();
  int bsz = B.size();
  int hour = 0;
  int min = 0;
  int b = asz - 1;
  for (int i = 0; i < asz; i++) {
    hour += cc(A[i]) * power(50, b);
    b--;
  }
  b = bsz - 1;
  for (int i = 0; i < bsz; i++) {
    min += cc(B[i]) * power(50, b);
    b--;
  }
  int res = 0;
  bool isInfinite = false;
  bool isEligible = false;
  if (hour <= 23 && min <= 59) {
    res = -1;
    isInfinite = true;
  }
  vector<int> output;
  if (!isInfinite) {
    for (int j = 1; j <= 36; j++) {
      isEligible = true;
      for (int i = 0; i < asz; i++) {
        if (cc(A[i]) >= j) {
          isEligible = false;
          break;
        }
      }
      for (int i = 0; i < bsz; i++) {
        if (cc(B[i]) >= j) {
          isEligible = false;
          break;
        }
      }
      if (isEligible) {
        hour = 0;
        min = 0;
        b = asz - 1;
        for (int i = 0; i < asz; i++) {
          hour += cc(A[i]) * power(j, b);
          b--;
        }
        b = bsz - 1;
        for (int i = 0; i < bsz; i++) {
          min += cc(B[i]) * power(j, b);
          b--;
        }
      }
      if (hour <= 23 && min <= 59) {
        output.push_back(j);
      }
    }
  }
  if (isInfinite)
    printf("%d\n", res);
  else if (output.size() == 0)
    printf("0\n");
  else {
    for (int i = 0; i < output.size() - 1; i++) {
      printf("%d ", output[i]);
    }
    printf("%d\n", output[output.size() - 1]);
  }
  return 0;
}
