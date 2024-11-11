#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, n, cnt[30], ck = 0;
  string s, t;
  cin >> p;
  while (p--) {
    memset(cnt, 0, sizeof(cnt));
    ck = 0;
    cin >> n;
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
      cnt[s[i] - 'a']++;
      cnt[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 2 == 1) {
        ck = 1;
        break;
      }
    }
    if (ck == 1) {
      cout << "No" << endl;
    } else {
      vector<pair<int, int> > ans;
      for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = i + 1; j < n; j++) {
          if (s[i] == s[j]) {
            swap(t[i], s[j]);
            ans.push_back({j, i});
            found = 1;
            break;
          }
        }
        if (found == 0) {
          for (int j = i + 1; j < n; j++) {
            if (s[i] == t[j]) {
              swap(s[j], t[j]);
              ans.push_back({j, j});
              swap(t[i], s[j]);
              ans.push_back({j, i});
              found = 1;
              break;
            }
          }
        }
      }
      cout << "Yes" << endl;
      cout << ans.size() << endl;
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
      }
    }
  }
}
