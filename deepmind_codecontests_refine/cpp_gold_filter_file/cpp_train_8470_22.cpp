#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
  int n;
  cin >> n;
  for (int i = n + 1; i < 900000; i++) {
    int m = i;
    int b = 1;
    memset(a, 0, sizeof(a));
    while (m > 0) {
      int b = m % 10;
      a[b]++;
      m = m / 10;
    }
    for (int j = 0; j < 10; j++) {
      if (a[j] > 1) b = 0;
    }
    if (b) {
      cout << i;
      break;
    }
  }
}
