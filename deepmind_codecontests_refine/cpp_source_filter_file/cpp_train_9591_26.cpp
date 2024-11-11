#include <bits/stdc++.h>
long long arr[101];
long long i, j, mx, k, n, e, s;
int main() {
  std::cin >> n >> k;
  for (i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  mx = -1000;
  for (i = 0; i < k; i++) {
    e = 0;
    s = 0;
    for (j = i; j < n; j++) {
      if (i - j % k != 0) {
        if (arr[j] == 1)
          e++;
        else
          s--;
      }
    }
    if (abs(e - s) > mx) mx = abs(e - s);
  }
  std::cout << mx << std::endl;
  return 0;
}
