#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int nums[10000];
int the_one;
int bo;
int diff(int i) {
  bo = the_one;
  int diff = 0;
  while (nums[i] != 0 || bo != 0) {
    int n1 = nums[i] % 2;
    int n2 = bo % 2;
    if (n1 != n2) diff++;
    nums[i] /= 2;
    bo /= 2;
  }
  if (diff > k) return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> nums[i];
  }
  cin >> the_one;
  int res = 0;
  for (int i = 0; i < k; i++) {
    res += diff(i);
  }
  cout << res;
  return 0;
}
