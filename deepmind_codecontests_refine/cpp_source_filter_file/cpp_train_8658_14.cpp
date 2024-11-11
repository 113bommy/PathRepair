#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, r;
  cin >> n >> l >> r;
  long long minsum = (n - l) + 1;
  l--;
  int j = 1;
  while (j <= l) {
    minsum += pow(2, l);
    j++;
  }
  long long maxsum = 0;
  for (int i = 0; i < (n - r) + 1; i++) maxsum += pow(2, r - 1);
  r--;
  int k = r;
  while (k > 0) {
    maxsum += pow(2, k - 1);
    k--;
  }
  cout << minsum << " " << maxsum;
  return 0;
}
