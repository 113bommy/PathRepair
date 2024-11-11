#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000000], i, b[100000];
int revert(int m) {
  int idx = 0;
  while (m > 0) {
    idx *= 10;
    idx += (m % 10);
    m /= 10;
  }
  return idx;
}
int main() {
  int w = 1;
  cin >> n;
  for (int i = 2; i <= 100000; i++) {
    for (int j = 2 * i; j <= 100000; j += i) {
      a[j] = 1;
    }
  }
  for (int i = 13; i <= 100000; i++) {
    if (a[i] == 0 && a[revert(i)] == 0 && i != (revert(i))) {
      b[w] = i;
      w++;
    }
  }
  cout << b[n] << endl;
}
