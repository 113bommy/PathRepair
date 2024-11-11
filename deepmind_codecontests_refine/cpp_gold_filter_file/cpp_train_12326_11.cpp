#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  int n;
  cin >> n;
  vector<long long> nums(n), subSums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    if (i > 0) {
      if (nums[i] < 0)
        subSums[i] = subSums[i - 1];
      else
        subSums[i] = subSums[i - 1] + nums[i];
    } else
      subSums[i] = nums[i];
  }
  long long maxB = n * (-1000000000ll) - 9;
  pair<int, int> range = pair<int, int>(0, 0);
  for (int i = 0; i < n; i++) {
    long long sN = nums[i];
    for (int j = i + 1; j < n; j++) {
      if (nums[j] != sN) continue;
      long long nMaxB = subSums[j - 1] - subSums[i] + nums[i] + nums[j];
      if (nMaxB > maxB) {
        maxB = nMaxB;
        range = pair<int, int>(i, j);
      }
    }
  }
  int negatives = 0;
  for (int i = range.first + 1; i < range.second; i++) {
    if (nums[i] < 0) negatives++;
  }
  cout << maxB << " " << n - (range.second - range.first + 1) + negatives
       << endl;
  for (int i = 0; i < range.first; i++) {
    cout << i + 1 << " ";
  }
  for (int i = range.first + 1; i < range.second; i++) {
    if (nums[i] < 0) cout << i + 1 << " ";
  }
  for (int i = range.second + 1; i < n; i++) {
    cout << i + 1 << " ";
  }
  cout << endl;
  return 0;
}
