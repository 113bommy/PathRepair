#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, a, b;
  cin >> k >> a >> b;
  string s;
  cin >> s;
  int n = (int)s.size();
  if (a * k > n || b * k < n) {
    cout << "No solution\n";
    return 0;
  }
  int left = 0;
  for (; k > 0; k--) {
    int r = (s.size() - left) / k;
    cout << s.substr(left, r) << "\n";
    left += r;
  }
}
