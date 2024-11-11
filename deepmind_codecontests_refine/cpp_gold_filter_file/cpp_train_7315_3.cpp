#include <bits/stdc++.h>
using namespace std;
class Solution {
  int n;

 public:
  Solution() {
    cin >> n;
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  bool solve() {
    bool desc = true;
    int prev = INT_MAX;
    while (n--) {
      int a;
      cin >> a;
      if (prev <= a) {
        desc = false;
      }
      prev = a;
    }
    return !desc;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) Solution solution;
}
