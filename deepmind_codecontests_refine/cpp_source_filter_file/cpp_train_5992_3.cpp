#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > nums;
  int temp;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    nums.push_back(make_pair(temp, i));
  }
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n / 2; ++i) {
    cout << nums[i].second << " " << nums[n - i - 1].second << endl;
  }
}
