#include <bits/stdc++.h>
using namespace std;
int main() {
  int total, *nums, i, ins = 0;
  unsigned long sum = 0;
  cin >> total;
  nums = new int[total];
  for (i = 0; i < total; ++i) {
    cin >> nums[i];
    sum += nums[i];
  }
  if (sum % total != 0)
    cout << -1;
  else {
    sum /= total;
    for (i = 0; i < total; ++i)
      if (nums[i] == sum) ins++;
    cout << ins << endl;
    for (i = 0; i < total; ++i)
      if (nums[i] == sum) cout << i + 1 << ' ';
  }
  delete (nums);
  return 0;
}
