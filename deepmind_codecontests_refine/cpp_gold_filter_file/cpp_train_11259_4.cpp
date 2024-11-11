#include <bits/stdc++.h>
using namespace std;
int rd() {
  int sum = 0, flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = (sum << 1) + (sum << 3) + ch - '0';
    ch = getchar();
  }
  return flag * sum;
}
long long RD() {
  long long sum = 0, flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = (sum << 1) + (sum << 3) + ch - '0';
    ch = getchar();
  }
  return flag * sum;
}
int main() {
  int m = rd(), n = rd();
  int mi = 11111111, k = -1;
  for (int i = 1; i <= m; i++) {
    int x = rd();
    int t = rd();
    int num;
    if (x >= n) {
      num = x;
    } else {
      int ti = (n - x) / t;
      num = ti * t + x;
      if (num < n) num += t;
    }
    if (num < mi) {
      mi = num;
      k = i;
    }
  }
  cout << k << endl;
  return 0;
}
