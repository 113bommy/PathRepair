#include <bits/stdc++.h>
using namespace std;
int func(int temp);
int main() {
  int x2;
  cin >> x2;
  int i;
  int temp = func(x2);
  int res;
  if (x2 == temp) {
    res = x2;
  } else {
    res = x2 - temp + 1;
  }
  int a[res + 1];
  for (i = 1; i <= res; i++) {
    a[i] = 0;
  }
  a[1] = 1;
  int d = sqrt(res + 1) + 1;
  for (i = 2; i <= d; i++) {
    if (a[i] == 0) {
      int k = 2;
      while (k * i <= res) {
        a[k * i] = 1;
        k++;
      }
    }
  }
  int m;
  if (res % 2 == 0)
    m = res - 1;
  else
    m = res;
  for (i = 2; i < res; i++) {
    if (a[i] == 0) {
      int q;
      if (res % i == 0)
        q = res - i + 1;
      else
        q = res - res % i + 1;
      if (q < m && q + i <= x2) m = q;
    }
  }
  cout << m;
}
int func(int temp) {
  int i;
  for (i = 2; temp != 1; i++) {
    while (temp % i == 0) {
      temp = temp / i;
    }
  }
  i--;
  return i;
}
