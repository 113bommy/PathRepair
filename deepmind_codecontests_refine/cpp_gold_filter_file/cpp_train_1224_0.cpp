#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  pair<int, int> f[n], s[m];
  for (int i = 0; i < n; i++) {
    cin >> f[i].first >> f[i].second;
    if (f[i].first > f[i].second) {
      swap(f[i].first, f[i].second);
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> s[i].first >> s[i].second;
    if (s[i].first > s[i].second) {
      swap(s[i].first, s[i].second);
    }
  }
  bool mightNotKnow = false;
  set<int> options;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (f[i] == s[j]) continue;
      int common;
      int notCommonf, notCommons;
      if (f[i].first == s[j].first) {
        common = f[i].first;
        notCommonf = f[i].second;
        notCommons = s[j].second;
      } else if (f[i].first == s[j].second) {
        common = f[i].first;
        notCommonf = f[i].second;
        notCommons = s[j].first;
      } else if (f[i].second == s[j].first) {
        common = f[i].second;
        notCommonf = f[i].first;
        notCommons = s[j].second;
      } else if (f[i].second == s[j].second) {
        common = f[i].second;
        notCommonf = f[i].first;
        notCommons = s[j].first;
      } else {
        continue;
      }
      options.insert(common);
      for (int k = 0; k < n; k++) {
        if (f[k] == s[j]) continue;
        if (f[k].first == notCommons) mightNotKnow = true;
        if (f[k].second == notCommons) mightNotKnow = true;
      }
      for (int k = 0; k < m; k++) {
        if (s[k] == f[i]) continue;
        if (s[k].first == notCommonf) mightNotKnow = true;
        if (s[k].second == notCommonf) mightNotKnow = true;
      }
    }
  }
  if (options.size() == 1) {
    cout << *(options.begin()) << endl;
  } else if (mightNotKnow == false) {
    cout << 0 << endl;
  } else {
    cout << -1 << endl;
  }
}
