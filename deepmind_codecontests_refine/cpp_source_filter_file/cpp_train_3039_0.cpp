#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > ve;
string s;
int main() {
  int n, t, k;
  cin >> t;
  while (t--) {
    cin >> n >> k >> s;
    string t = "";
    for (int i = 0; i < k; i++) {
      t += '(';
      t += ')';
    }
    for (int i = 0; i < n / 2 - k + 1; i++) {
      t += '(';
    }
    for (int i = 0; i < n / 2 - k + 1; i++) {
      t += ')';
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == t[i])
        continue;
      else {
        int p = i;
        while (s[i] == s[p]) p++;
        ve.push_back({i, p});
        swap(s[i], s[p]);
      }
    }
    cout << ve.size() << endl;
    for (auto to : ve) cout << to.first + 1 << " " << to.second + 1 << endl;
    ve.clear();
  }
}
