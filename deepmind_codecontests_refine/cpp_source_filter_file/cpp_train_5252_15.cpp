#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  int n, cnt = 0;
  cin >> n;
  int a[100];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    int k, x = 0;
    cin >> k;
    while (k != 0) {
      x = x + k % 10;
      k = k / 10;
    }
    a[x]++;
  }
  for (int i = 1; i < 100; i++) {
    if (a[i] > 0) {
      a[i] = a[i] - 1;
      for (int j = i; j < 100; j++) {
        if (a[j] > 0 && (i + j) % 3 == 0) {
          cnt++;
          a[j]--;
          break;
        }
      }
    }
  }
  cout << cnt;
  return 0;
}
