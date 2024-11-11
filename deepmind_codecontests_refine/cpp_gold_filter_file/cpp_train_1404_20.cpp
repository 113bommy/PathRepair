#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int N;
int K;
int main() {
  cin >> N >> K;
  vector<tuple<int, int>> nums;
  for (int i = 0, _i = (N); i < _i; ++i) {
    int a;
    cin >> a;
    nums.emplace_back(a, i + 1);
  }
  sort((nums).begin(), (nums).end());
  vector<int> inds;
  int valid = 0;
  for (auto p : nums) {
    int x, y;
    tie(x, y) = p;
    if (x > K) break;
    inds.push_back(y);
    valid++;
    K -= x;
  }
  cout << inds.size() << "\n";
  for (auto x : inds) cout << x << " ";
  return 0;
}
