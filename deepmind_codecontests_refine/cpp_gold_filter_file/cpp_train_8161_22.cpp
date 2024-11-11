#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void solve(std::istream& in, std::ostream& out) {
    int n, m;
    in >> n >> m;
    vector<int> nums;
    int sum = 0;
    for (int i = 0; i < (n - 1); i++) {
      nums.push_back(0);
      sum += i;
    }
    nums.push_back(m);
    for (int i = 0; i < n; i++) {
      for (auto x : nums) {
        out << x << " ";
      }
      out << endl;
      int shift = nums[nums.size() - 1];
      for (int j = n - 1; j > 0; j--) {
        nums[j] = nums[j - 1];
      }
      nums[0] = shift;
    }
  }
};
void solve(std::istream& in, std::ostream& out) {
  out << std::setprecision(12);
  Solution solution;
  solution.solve(in, out);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  istream& in = cin;
  ostream& out = cout;
  solve(in, out);
  return 0;
}
