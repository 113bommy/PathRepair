#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  int n, k;
  int tmp;
  while (cin >> n >> k) {
    int sum = 0;
    int oddnum = 0;
    int evennum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum = (sum + a[i]) % 2;
      if (a[i] % 2)
        oddnum += 1;
      else
        evennum += 1;
    }
    if (n == k) {
      if (sum)
        puts("Stannis");
      else
        puts("Daenerys");
      continue;
    }
    if ((n - k) % 2) {
      if (k % 2) {
        if ((n - k) / 2 >= oddnum) {
          puts("Daenerys");
        } else {
          puts("Stannis");
        }
      } else {
        if ((n - k) / 2 >= min(oddnum, evennum)) {
          puts("Daenerys");
        } else {
          puts("Stannis");
        }
      }
    } else {
      if (k % 2) {
        if ((n - k) / 2 == evennum) {
          puts("Stannis");
        } else {
          puts("Daenerys");
        }
      } else {
        puts("Daenerys");
      }
    }
  }
  return 0;
}
