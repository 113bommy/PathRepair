#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  int n, tmp;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums.push_back(tmp);
  }
  deque<int> dedupe;
  for (int j = n - 1; j >= 0; j--) {
    deque<int>::iterator iter = find(dedupe.begin(), dedupe.end(), nums[j]);
    if (iter == dedupe.end()) {
      dedupe.push_front(nums[j]);
    }
  }
  cout << dedupe.size() << '\n';
  for (auto c : dedupe) {
    cout << c << ' ';
  }
  cout << '\n';
}
