#include <bits/stdc++.h>
using namespace std;
int n, m, p, s, q, t, i, j, k, x, y, z, a, b, c, d, l, r, lst, mn, mx, ans, cnt;
string str;
int main() {
  cin >> n;
  int nums[n];
  for (i = 0; i < n; i++) cin >> nums[i];
  sort(nums, nums + n);
  a++;
  for (i = 1; i < n; i++) {
    if (nums[i] >= a) a++;
  }
  cout << a - 1;
}
