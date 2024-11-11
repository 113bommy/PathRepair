#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  pair<int, int> nums[n];
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums[i] = make_pair(tmp, i);
  }
  sort(nums, nums + n);
  int sum = 0;
  int i = 0;
  string ans = "";
  while (i < n) {
    if (sum + nums[i].first > k) break;
    sum += nums[i].first;
    i++;
  }
  cout << i << "\n";
  for (int j = 0; j < i; j++) cout << nums[j].second << " ";
  cout << "\n";
  return 0;
}
