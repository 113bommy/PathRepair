#include <bits/stdc++.h>
using namespace std;
int k;
int main() {
  cin >> k;
  while (k--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int a[27] = {0};
    for (int i = 0; i < n; i++) {
      a[s[i] - 'a']++;
      a[t[i] - 'a']++;
    }
    bool ans = 1;
    for (int i = 0; i < 26; i++)
      if (a[i] % 2) ans = 0;
    if (ans == 0) {
      puts("NO");
      continue;
    } else
      puts("YES");
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
      if (s[i] == t[i]) continue;
      int x = -1, y = -1;
      for (int j = i + 1; j < n; j++)
        if (s[j] == s[i]) {
          x = j;
          break;
        }
      for (int j = i + 1; j < n; j++)
        if (t[j] == s[i]) {
          y = j;
          break;
        }
      if (x != -1) {
        swap(t[i], s[x]);
        v.push_back({i, x});
      } else {
        swap(t[y], s[y]);
        swap(s[y], t[i]);
        v.push_back({y, y});
        v.push_back({i, y});
      }
    }
    cout << v.size() << endl;
    for (auto i : v) cout << i.second + 1 << ' ' << i.first + 1 << endl;
  }
}
