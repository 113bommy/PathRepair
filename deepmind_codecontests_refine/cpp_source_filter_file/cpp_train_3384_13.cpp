#include <bits/stdc++.h>
using namespace std;
const int size = 505050;
int arr[size];
int modify(int l, int r, std::ostream& out) {
  if (l == r) return 0;
  if (arr[l] == arr[r]) {
    for (int i = l + 1; i < r; i++) arr[i] = arr[l];
    return (r - l) / 2;
  } else {
    int m = (l + r + 1) / 2;
    for (int i = l + 1; i < m; i++) {
      arr[i] = arr[l];
    }
    for (int i = m + 1; i < r; i++) {
      arr[i] = arr[r];
    }
    return (r - l - 1) / 2;
  }
}
class Solution {
 public:
  void solve(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    for (int i = 0; i < n; i++) {
      in >> arr[i];
    }
    int ans = 0;
    int lb = 0;
    for (int i = 0; i < n; i++) {
      if (i == n - 1 || arr[i] == arr[i + 1]) {
        ans = max(ans, modify(lb, i, out));
        lb = i + 1;
      }
    }
    out << ans << endl;
    for (int i = 0; i < n; i++) {
      out << arr[i] << " ";
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
