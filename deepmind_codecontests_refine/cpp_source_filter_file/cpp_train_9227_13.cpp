#include <bits/stdc++.h>
using namespace std;
class Solution {
  int n, x[2];
  vector<pair<long long, int>> A;

 public:
  void run() {
    cin >> n >> x[0] >> x[1];
    for (int i = 0; i < n; ++i) {
      int c;
      cin >> c;
      A.emplace_back(c, i);
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < n; ++i) {
      int a = A[i].first;
      int j = (x[0] + a - 1) / a + i;
      if (j < n and x[1] <= A[j].first * (n - j)) {
        cout << "Yes\n";
        cout << j << ' ' << n - j << '\n';
        for (int k = i; k < j; ++k)
          cout << A[k].second + 1 << " \n"[k == j - 1];
        for (int k = j; k < n; ++k)
          cout << A[k].second + 1 << " \n"[k == n - 1];
        return;
      }
      j = (x[1] + a - 1) / a + i;
      if (j < n and x[0] <= A[j].first * (n - j)) {
        cout << "Yes\n";
        cout << n - j << ' ' << j << '\n';
        for (int k = j; k < n; ++k)
          cout << A[k].second + 1 << " \n"[k == n - 1];
        for (int k = i; k < j; ++k)
          cout << A[k].second + 1 << " \n"[k == j - 1];
        return;
      }
    }
    cout << "No\n";
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  Solution().run();
}
