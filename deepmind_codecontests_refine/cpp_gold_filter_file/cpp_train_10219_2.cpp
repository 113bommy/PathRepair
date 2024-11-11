#include <bits/stdc++.h>
using namespace std;
class Solver {
 public:
  void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    first.resize(n + 1, -1);
    last.resize(n + 1, -1);
    for (int i = 0; i < k; ++i) {
      long long temp;
      cin >> temp;
      last[temp] = i;
      if (first[temp] == -1) {
        first[temp] = i;
      }
    }
    long long result = 0;
    for (int i = 1; i <= n; ++i) {
      if (valid(i, i - 1)) {
        result++;
      }
      if (valid(i, i)) {
        result++;
      }
      if (valid(i, i + 1)) {
        result++;
      }
    }
    cout << result << endl;
  }
  bool valid(int i, int j) {
    if (i == 0 || j == 0 || i > n || j > n) {
      return false;
    }
    if (first[i] == -1 || first[j] == -1) {
      return true;
    }
    if (last[j] >= first[i]) {
      return false;
    }
    return true;
  }
  vector<int> first, last;
  int n, k;
};
int main() {
  Solver sol;
  sol.solve();
  return 0;
}
