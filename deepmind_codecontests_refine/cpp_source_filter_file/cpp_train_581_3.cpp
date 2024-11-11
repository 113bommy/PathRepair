#include <bits/stdc++.h>
using namespace std;
char s[10000];
int num1[7], num2[7];
int sum1, sum2;
int ma1, mi1 = 10000, ma2, mi2 = 10000;
int n, n1, m, m1;
int main() {
  cin >> s;
  int l = 0, c = 0;
  for (int i = 0; i < 6; i++) {
    if (i < 3) {
      num1[l++] = s[i] - '0';
    } else {
      num2[c++] = s[i] - '0';
    }
  }
  sort(num1, num1 + 3);
  sort(num2, num2 + 3);
  mi1 = min(num1[0], min(num1[1], num1[2]));
  mi2 = min(num2[0], min(num2[1], num2[2]));
  ma1 = max(num1[0], max(num1[1], num1[2]));
  ma2 = max(num2[0], max(num2[1], num2[2]));
  for (int i = 0; i < 3; i++) {
    sum1 += num1[i];
    if (num1[i] == mi1) {
      n++;
    }
    if (num1[i] == ma1) {
      n1++;
    }
  }
  for (int i = 0; i < 3; i++) {
    sum2 += num2[i];
    if (num2[i] == mi2) {
      m++;
    }
    if (num2[i] == ma2) {
      m1++;
    }
  }
  if (sum1 > sum2) {
    for (int i = 0; i < 3; i++) {
      if (num1[i] >= sum1 - sum2) {
        cout << 1;
        return 0;
      }
    }
    for (int i = 0; i < 3; i++) {
      if (9 - num2[i] >= sum1 - sum2) {
        cout << 1;
        return 0;
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 2; j >= 0; j--) {
        if (num1[i] + 9 - num2[j] >= sum1 - sum2) {
          cout << 2;
          return 0;
        }
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (j == i) {
          continue;
        }
        if (num1[i] + num1[j] >= sum1 - sum2) {
          cout << 2;
          return 0;
        }
      }
    }
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        if (i == j) {
          continue;
        }
        if (18 - num2[i] - num2[j] >= sum2 - sum1) {
          cout << 2;
          return 0;
        }
      }
    cout << 3;
    return 0;
  }
  if (sum2 > sum1) {
    for (int i = 0; i < 3; i++) {
      if (num2[i] >= sum2 - sum1) {
        cout << 1;
        return 0;
      }
    }
    for (int i = 0; i < 3; i++) {
      if (9 - num1[i] >= sum2 - sum1) {
        cout << 1;
        return 0;
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 2; j >= 0; j--) {
        if (num2[i] + 9 - num1[j] >= sum2 - sum1) {
          cout << 2;
          return 0;
        }
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (j == i) {
          continue;
        }
        if (num2[i] + num2[j] >= sum2 - sum1) {
          cout << 2;
          return 0;
        }
      }
    }
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        if (i == j) {
          continue;
        }
        if (18 - num1[i] - num1[j] >= sum2 - sum1) {
          cout << 2;
          return 0;
        }
      }
    cout << 3;
    return 0;
  }
  cout << 0;
  return 0;
}
