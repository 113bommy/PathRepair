#include <bits/stdc++.h>
using namespace std;
int nums[11];
int fact[10] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 0};
int pows[10] = {1,     10,     100,     1000,     10000,
                10000, 100000, 1000000, 10000000, 100000000};
int a[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int n, k;
int getSwapped(int n) {
  int kk = 0;
  for (int i = 0; i < k; i++) {
    int dig = n % 10;
    n /= 10;
    kk += dig * pows[a[k - i - 1]];
  }
  return kk;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> nums[i];
  int mn = 1000000000, mx = 0, diff = 1000000000;
  for (int i = 0; i < fact[k]; i++) {
    int mn = 1000000000, mx = 0;
    for (int j = 0; j < n; j++) {
      mn = min(mn, getSwapped(nums[j]));
      mx = max(mx, getSwapped(nums[j]));
    }
    diff = min(diff, mx - mn);
    next_permutation(a, a + k);
  }
  cout << diff;
}
