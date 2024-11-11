#include <bits/stdc++.h>
using namespace std;
vector<char> order;
int how_t[26], how_s[26], s_added[26];
int que = 0;
bool check(int l) {
  int needed = 0;
  for (int i = 0; i < 26; i++) {
    if (how_t[i] * l > how_s[i]) {
      needed += how_t[i] * l - how_s[i];
    }
  }
  if (needed > que) {
    return false;
  }
  return true;
}
int main() {
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '?') {
      que++;
    } else {
      how_s[s[i] - 97]++;
    }
    order.push_back(s[i]);
  }
  for (int i = 0; i < t.size(); i++) {
    how_t[t[i] - 97]++;
  }
  int l = 0, r = s.size() / t.size();
  while (r - l > 1) {
    if (check((l + r) / 2) == true) {
      l = (l + r) / 2;
    } else {
      r = (l + r) / 2;
    }
  }
  if (check(r)) {
    l = r;
  }
  vector<int> added;
  for (int i = 0; i < 26; i++) {
    if (how_t[i] * l > how_s[i]) {
      for (int j = how_t[i] * l - how_s[i]; j >= 1; j--) {
        added.push_back(i);
      }
    }
  }
  int ind = 0;
  for (int i = 0; i < s.size(); i++) {
    if (order[i] != '?') {
      cout << order[i];
    } else {
      if (ind < added.size()) {
        char w = added[ind] + 97;
        cout << w;
        ind++;
      } else {
        cout << "a";
      }
    }
  }
  return 0;
}
