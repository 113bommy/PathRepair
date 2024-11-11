#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n == 1 || n == 2) {
    cout << 1;
    return 0;
  }
  for (long long i = 1; i < 1e5; i++) {
    long long start, ends, res;
    if (i % 2 == 0) {
      if (i == 2) {
        start = i;
        ends = i + (i - 1);
      } else if (i == 4) {
        start = 7;
        ends = 10;
      } else {
        start = i + ((((i / 2) - 1) * i) - ((i / 2) - 1));
        ends = start + (i - 1);
      }
      if (start <= n && ends >= n) {
        res = (n - start) + 1;
        cout << res;
        break;
      }
    } else {
      if (i == 1) {
        start = ends = 1;
      }
      start = i + (ends - (i - 1));
      ends = start + (i - 1);
      if (start <= n && ends >= n) {
        res = (n - start) + 1;
        cout << res;
        break;
      }
    }
  }
  return 0;
}
