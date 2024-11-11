#include <bits/stdc++.h>
using namespace std;
int distance(int x1, int y1, int x2, int y2) {
  return (int)ceil(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, x, q, cnt = 0;
  string t;
  char ch;
  map<char, vector<pair<int, int>>> keys;
  int freq[26] = {0};
  cin >> n >> m >> x;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> ch;
      if (!freq[ch - 'a']) freq[ch - 'a']++;
      keys[ch].push_back(make_pair(i, j));
    }
  }
  if (keys.count('S')) {
    vector<pair<int, int>> shiftCords = keys['S'];
    vector<pair<int, int>> chCords;
    for (int i = 'a'; i <= 'z'; i++) {
      if (keys.count(i)) {
        chCords = keys[i];
        bool validDistance = 0;
        for (int j = 0; j < (int)chCords.size(); j++) {
          for (int k = 0; k < (int)shiftCords.size(); k++) {
            if (distance(chCords[j].first, chCords[j].second,
                         shiftCords[k].first, shiftCords[k].second) <= x) {
              freq[i - 'a']++;
              validDistance = 1;
              break;
            }
          }
          if (validDistance) break;
        }
      }
    }
  }
  cin >> q;
  cin >> t;
  for (int i = 0; i < q; i++) {
    char c = t[i];
    if (islower(c)) {
      if (!freq[c - 'a']) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      c = tolower(c);
      if (!keys.count('S') || !freq[c - 'a']) {
        cout << -1 << endl;
        return 0;
      } else {
        if (freq[c - 'a'] == 1) cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
