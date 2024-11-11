#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  int n;
  cin >> n;
  vector<int> cnt(30, 0);
  for (int i = 0; i < n; ++i) {
    char x;
    cin >> x;
    ++cnt[x - 'a'];
  }
  int mini = INT32_MAX, t = 0;
  for (auto& i : cnt) {
    if (i) mini = min(mini, i);
    if (i == 1) ++t;
  }
  if (t == n && n > 1)
    cout << "No\n";
  else
    cout << "Yes\n";
}
