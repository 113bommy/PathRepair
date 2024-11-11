#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void solve() {
    long long int l, r;
    cin >> l >> r;
    vector<long long int> v = {-1};
    for (long long int i = l; i <= r; i++) {
      v.push_back(i);
    }
    long long int cnt = 0;
    long long int ind = 1;
    while (cnt < v.size() / 2) {
      cout << v[ind] << " " << v[ind + 1] << endl;
      ind += 2;
      cnt += 2;
    }
  }
  void solving(long long int t) {
    for (long long int i = 0; i < t; i++) {
      solve();
    }
  }
};
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int t = 1;
  Solution solution;
  cout << "YES\n";
  solution.solving(t);
  return 0;
}
