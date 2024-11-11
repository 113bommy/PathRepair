#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  --s;
  int ans = 0;
  if (a[s] != 0) {
    ans++;
    a[s] = 0;
  }
  int pseudo = 0;
  for (int i = 0; i < n; ++i) {
    if (s != i && a[i] == 0) {
      pseudo++;
    }
  }
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      b.push_back(a[i]);
    }
  }
  sort(b.begin(), b.end());
  set<int> c;
  int best = n - 1;
  for (int i = 0; i < b.size(); ++i) {
    c.insert(b[i]);
    int mistake = pseudo + b.size() - i - 1;
    if (mistake >= b[i] - c.size()) {
      best = min(best, mistake);
    } else if (b[i] <= n - 1) {
      best = min(best, b[i] - (int)c.size());
    }
  }
  cout << ans + best << endl;
  return 0;
}
