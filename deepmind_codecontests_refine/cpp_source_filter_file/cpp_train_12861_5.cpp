#include <bits/stdc++.h>
using namespace std;
unsigned long long int cubes[100005];
unsigned long long int isOk(unsigned long long int m,
                            unsigned long long int maxValue) {
  unsigned long long int taken = 0;
  for (unsigned long long int i = 2; i <= 100005; i++) {
    unsigned long long int now = (maxValue / (i * i * i));
    if (now == 0) break;
    taken += now;
  }
  return taken;
}
int main(void) {
  unsigned long long int i, j, n;
  cin >> n;
  unsigned long long int start = 1, end = 1000000000000000000;
  while (start <= end) {
    unsigned long long int mid = (start + end) / 2;
    if (isOk(n, mid) == n) {
      if (mid == 1) {
        cout << mid;
        return 0;
      }
      if (isOk(n, mid - 1) != n) {
        cout << mid;
        return 0;
      }
      end = mid - 1;
    } else if (isOk(n, mid) > n)
      end = mid - 1;
    else
      start = mid + 1;
  }
  cout << "-1";
  return 0;
}
