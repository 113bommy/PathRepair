#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    if (n == 0) {
      printf("0 1\n");
      continue;
    }
    printf("-%lld %lld\n", n - 1, n);
  }
  return 0;
}
