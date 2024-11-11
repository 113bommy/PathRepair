#include <bits/stdc++.h>
using namespace std;
int n;
string s, t;
vector<pair<char, int>> b[26];
int loc1[26], loc2[26];
int main() {
  scanf("%d", &n);
  cin >> s >> t;
  int h = 0, ans = 0, ans1 = -1, ans2 = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      ++h;
      if (ans != 2) {
        loc1[s[i] - 'a'] = i + 1;
        loc2[t[i] - 'a'] = i + 1;
        b[s[i] - 'a'].push_back(make_pair(t[i], i + 1));
      }
      if (ans != 2) {
        for (auto c : b[t[i] - 'a']) {
          if (c.first == s[i]) {
            ans = 2;
            ans1 = c.second;
            ans2 = i + 1;
            break;
          }
        }
      }
      if (ans != 2) {
        if (loc1[t[i] - 'a'] != 0) {
          ans = 1;
          ans1 = loc1[t[i] - 'a'];
          ans2 = i + 1;
        }
        if (loc2[s[i] - 'a'] != 0) {
          ans = 1;
          ans1 = loc2[s[i] - 'a'];
          ans2 = i + 1;
        }
      }
    }
  }
  if (ans == 2) {
    printf("%d\n%d %d", (h - 2), ans1, ans2);
  } else if (ans == 1) {
    printf("%d\n%d %d", (h - 1), ans1, ans2);
  } else {
    printf("%d\n%d %d", h, -1, -1);
  }
}
