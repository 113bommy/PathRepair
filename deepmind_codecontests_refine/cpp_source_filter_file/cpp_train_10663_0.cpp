#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  return is >> p.first >> p.second;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p) {
  return os << p.first << " " << p.second;
}
const int s = 1000000;
bool used[s + 1];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    used[x] = 1;
  }
  vector<int> ans;
  int t = 0;
  for (int i = 1; i <= s; i++) {
    if (used[i]) {
      if (!used[s + 1 - i]) {
        ans.push_back(s + 1 - i);
      } else
        t++;
    }
  }
  for (int i = 1; i <= s; i++) {
    if (t > 0 && !used[i] && !used[s + 1 - i]) {
      used[i] = used[s + 1 - i] = 1;
      t--;
      ans.push_back(i);
      ans.push_back(s + 1 - i);
    }
  }
  cout << ans.size() << "\n";
  for (int x : ans) cout << x << " ";
}
