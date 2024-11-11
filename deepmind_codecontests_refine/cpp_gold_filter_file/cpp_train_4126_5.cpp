#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> ans(0);
  int h = 100, x = 0, s = 0, p;
  if (n < h) h = n;
  while (h > 0) {
    x = n - h;
    p = x;
    while (p > 0) {
      s += p % 10;
      p /= 10;
    }
    if (s == h) {
      ans.push_back(x);
    }
    s = 0;
    h--;
  }
  cout << ans.size() << endl;
  int l = 0;
  while (l < ans.size()) {
    cout << ans[l] << " ";
    l++;
  }
}
