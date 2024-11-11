#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int k;
  cin >> k;
  string s;
  cin >> s;
  int n = s.length();
  vector<int> p;
  p.reserve(n + 2);
  p.push_back(-1);
  for (int i = 0; i < n; ++i)
    if (s[i] == '1') p.push_back(i);
  p.push_back(n);
  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    if (i + k >= p.size()) {
      break;
    }
    long long nleft = p[i] - p[i - 1];
    long long nright = p[i + k] - p[i + k - 1];
    if (k == 0) {
      long long x = nleft - 1;
      ans += x * (x + 1) / 2;
    } else {
      ans += nleft * nright;
    }
  }
  cout << ans;
  return 0;
}
