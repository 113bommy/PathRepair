#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> h, s;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  h.resize(n);
  for (int i = 0; i < n; ++i) cin >> h[i];
  s = h;
  for (int i = (int)s.size() - 2; i >= 0; --i) s[i] = max(s[i], s[i + 1]);
  for (int i = 0; i < (int)s.size(); ++i) {
    if (i + 1 == (int)s.size()) {
      cout << 0 << endl;
    } else if (s[i + 1] > h[i]) {
      cout << s[i + 1] - h[i] + 1 << ' ';
    } else {
      cout << 0 << ' ';
    }
  }
  return 0;
}
