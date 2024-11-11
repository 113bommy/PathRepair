#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  k = (n - k) / 2 + 1;
  for (int i = 0; i < n; i++) {
    if (i % k == 0)
      printf("1");
    else
      printf("0");
  }
  return 0;
}
