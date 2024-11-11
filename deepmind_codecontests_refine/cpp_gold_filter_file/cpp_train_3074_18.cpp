#include <bits/stdc++.h>
using namespace std;
int a[55];
int main() {
  long long s, x;
  cin >> s >> x;
  int f = 0;
  for (int i = 0; i < 50; i++) {
    if ((x & ((long long)1 << i))) {
      s -= (long long)1 << i;
      a[i] = 1;
      f++;
    }
  }
  if (s % 2 == 1 || s < 0) {
    printf("0\n");
    return 0;
  }
  s = s / 2;
  for (int i = 0; i < 50; i++) {
    if ((s & ((long long)1 << i))) {
      if (a[i]) {
        printf("0\n");
        return 0;
      }
    }
  }
  if (s != 0) {
    long long p = 1;
    for (int i = 1; i <= f; i++) {
      p = p * 2;
    }
    cout << p << endl;
  } else {
    long long p = 1;
    for (int i = 1; i <= f; i++) {
      p = p * 2;
    }
    cout << p - 2 << endl;
  }
}
