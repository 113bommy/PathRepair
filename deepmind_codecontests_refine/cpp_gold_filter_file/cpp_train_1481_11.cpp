#include <bits/stdc++.h>
const long long MOD = ((long long)(1e9)) + 7;
using namespace std;
long long solve(std::vector<long long> &v, int bit) {
  std::vector<long long> left, right;
  if (bit < 0) return 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] >> bit & 1) {
      left.push_back(v[i]);
    } else
      right.push_back(v[i]);
  }
  if (left.size() == 0) {
    return solve(right, bit - 1);
  }
  if (right.size() == 0) {
    return solve(left, bit - 1);
  }
  return min(solve(left, bit - 1), solve(right, bit - 1)) + (1 << bit);
}
int main() {
  int n;
  cin >> n;
  std::vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  cout << solve(v, 30) << endl;
}
