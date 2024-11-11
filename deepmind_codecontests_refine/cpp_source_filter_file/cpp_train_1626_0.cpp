#include <bits/stdc++.h>
using namespace std;
int b[101];
int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0, c = 0; i < n; ++i) cin >> b[i];
  for (int i = 0, c = 1; i < n; ++i) {
    if (i < n - 1 && b[i] == b[i + 1])
      ++c;
    else
      a.push_back(c), c = 1;
  }
  int sz = a.size();
  if (sz == 1) {
    cout << n << endl;
    return 0;
  }
  int ad = 0;
  if (b[n - 1]) ad += a[sz - 1], --sz, a.pop_back();
  reverse(a.begin(), a.end());
  if (!b[0]) ad += a[sz - 1], --sz, a.pop_back();
  if (a.empty()) {
    cout << ad << endl;
    return 0;
  }
  for (int i = sz - 4; i > 0; i -= 2) a[i] += a[i + 2];
  int s = a[0];
  for (int i = 1; i < sz; i += 2) {
    if (i > 1) a[i] += a[i - 2];
    if (i < sz - 1)
      s = max(s, a[i] + a[i + 1]);
    else
      s = max(s, a[i]);
  }
  cout << s + ad << endl;
  return 0;
}
