#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tot;
  cin >> tot;
  vector<int> ar(tot);
  unordered_map<int, int> n, r;
  unordered_set<int> s;
  for (auto &i : ar) {
    cin >> i;
    ++n[i];
  }
  sort(ar.begin(), ar.end());
  long long ans = 1;
  for (int i = 0; i < 3; ++i) {
    ++r[ar[i]];
    s.insert(ar[i]);
  }
  for (auto &i : s) {
    if (r[i] == 2) {
      ans *= (n[i] * (n[i] - 1)) / 2;
    } else if (r[i] == 3) {
      ans *= (n[i] * (n[i] - 1) * (n[i] - 2)) / 6;
    } else {
      ans *= n[i];
    }
  }
  cout << ans << '\n';
  return 0;
}
