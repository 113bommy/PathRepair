#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
int main() {
  int t;
  cin >> t;
  for (long long _ = 0; _ < (t); ++_) {
    int n, a, b;
    cin >> n >> a >> b;
    string ans = "";
    for (long long i = 0; i < (a); ++i) {
      if ((i + 1) <= b) {
        ans = ans + string(1, ('a' + (i)));
      } else {
        ans = ans + string(1, ('a' + b - 1));
      }
    }
    for (int i = 0; i <= (n - a - 1); i++) {
      ans = ans + string(1, ans[i]);
    }
    cout << ans << endl;
  }
}
