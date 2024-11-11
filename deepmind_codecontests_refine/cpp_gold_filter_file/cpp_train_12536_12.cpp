#include <bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int c[200010];
int main() {
  int n;
  int i, j;
  long long sum = 0;
  int one, zero;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 0) {
      one++;
    } else {
      zero++;
    }
  }
  j = n - 1;
  for (i = 0; i < n; i++) {
    if (a[i] == 1) {
      if (i == 0) {
        b[i] = 1;
      } else {
        b[i] = b[i - 1] + 1;
      }
    } else {
      b[i] = b[i - 1];
    }
  }
  for (i = n - 1; i >= 0; i--) {
    if (a[i] == 0) {
      if (i == n - 1) {
        c[i] = 1;
      } else {
        c[i] = c[i + 1] + 1;
      }
    } else {
      c[i] = c[i + 1];
    }
  }
  if (one > zero) {
    zero = 0;
    for (i = n - 1; i >= 0; i--) {
      if (a[i] == 0) {
        sum = sum + b[i] + c[i] - 1 - zero;
        zero++;
      }
    }
  } else {
    for (i = 0; i < n; i++) {
      if (a[i] == 1) {
        sum = sum + c[i] + b[i] - 1 - one;
        one++;
      }
    }
  }
  cout << sum << endl;
  return 0;
}
