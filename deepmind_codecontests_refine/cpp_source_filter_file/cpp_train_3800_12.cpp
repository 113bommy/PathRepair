#include <bits/stdc++.h>
using namespace std;
const unsigned long long int oo = 1e9 + 5;
const int mx = 55;
int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  set<int> nums;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      if (x % i == 0 && x / i <= n && i < n) {
        nums.insert(x / i);
        nums.insert(i);
      }
    }
  }
  printf("%d", int(nums.size()));
  return 0;
}
