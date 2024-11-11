#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 7;
map<string, int>::iterator it;
map<string, int> mpp;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int cnt = 0;
    n = abs(n);
    if (n == 1 || n == -1)
      printf("1\n");
    else if (n == 0)
      printf("0\n");
    else {
      int cnt = 0;
      for (int i = 1;; i++) {
        long long sum = i + i * (i - 1) / 2;
        if (sum == n) {
          cnt = i;
          break;
        }
        if (sum > n && (sum - n) % 2 == 0) {
          cnt = i;
          break;
        }
      }
      printf("%d\n", cnt);
    }
  }
  return 0;
}
