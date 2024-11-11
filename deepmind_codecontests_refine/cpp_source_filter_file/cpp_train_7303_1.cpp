#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int main() {
  int i, N, maxi;
  cin >> N;
  nums.resize(N + 1);
  for (i = 1; i <= N; i++) cin >> nums[i];
  for (i = 1; i <= N; i++) {
    int num = 1;
    int j = i;
    while (nums[j] != -1) {
      j = nums[j];
      num++;
    }
    maxi = max(maxi, num);
  }
  cout << maxi << endl;
}
