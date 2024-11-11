#include <bits/stdc++.h>
using namespace std;
int a[1000001] = {0};
int main() {
  int n = 1000001, m, i, j, sq, k;
  sq = int(sqrt((double)i));
  for (i = 3; i <= sq; i += 2) {
    if (a[i] == 0) {
      for (j = i * i; j <= n; j += i + i) {
        a[j] = 1;
      }
    }
  }
  for (i = 3; i <= n; i += 2) {
    if (a[i] == 0) {
    }
  }
  for (i = 4; i < 1000001; i += 2) a[i] = 1;
  cin >> n;
  for (i = 1; i <= 10000; i++) {
    if (a[i * n + 1] == 1) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
