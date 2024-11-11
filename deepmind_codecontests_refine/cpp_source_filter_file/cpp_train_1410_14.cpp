#include <bits/stdc++.h>
using namespace std;
struct tr {
  int x;
  struct tr* left;
  struct tr* right;
};
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  set<int> s;
  map<int, int> left;
  map<int, int> right;
  int x;
  cin >> x;
  s.insert(x);
  for (int i = 1; i < n; ++i) {
    cin >> x;
    auto greater = s.upper_bound(x);
    if (greater != s.end() && !left.count(*greater))
      left[*greater] = x, cout << *greater;
    else
      --greater, right[*greater] = x, cout << *greater;
    if (i < n - 2) cout << " ";
    s.insert(x);
  }
  cout << endl;
}
