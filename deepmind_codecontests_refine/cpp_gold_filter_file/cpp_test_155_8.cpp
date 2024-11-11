#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int p[200005] = {0};
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    string s;
    cin >> s;
    vector<pair<int, int>> like;
    vector<pair<int, int>> dislike;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        dislike.push_back(make_pair(p[i], i));
      } else {
        like.push_back(make_pair(p[i], i));
      }
    }
    sort(dislike.begin(), dislike.end());
    sort(like.begin(), like.end());
    int pt = 1;
    for (int i = 0; i < dislike.size(); i++) {
      dislike[i].first = pt++;
    }
    for (int i = 0; i < like.size(); i++) {
      like[i].first = pt++;
    }
    sort(dislike.begin(), dislike.end(), compare);
    sort(like.begin(), like.end(), compare);
    int ans[200005] = {0};
    int d = 0, l = 0;
    for (int i = 0; i < n; i++) {
      if (d < dislike.size()) {
        if (dislike[d].second == i) {
          ans[i] = dislike[d++].first;
        }
      }
      if (l < like.size()) {
        if (like[l].second == i) {
          ans[i] = like[l++].first;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
