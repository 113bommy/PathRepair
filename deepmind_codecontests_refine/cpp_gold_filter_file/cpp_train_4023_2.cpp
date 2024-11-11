#include <bits/stdc++.h>
using namespace std;
int coun[101];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  set<char> chars;
  for (int i = 0; i < 26; i++) {
    chars.insert('a' + i);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    char event;
    cin >> event;
    string x;
    cin >> x;
    if (event == '.') {
      for (int i = 0; i < x.size(); i++) {
        if (chars.find(x[i]) != chars.end()) chars.erase(x[i]);
      }
    } else if (event == '?') {
      if (chars.size() == 1) {
        ans++;
      } else {
        if (chars.find(x[0]) != chars.end()) chars.erase(x[0]);
      }
    } else {
      if (chars.size() == 1) {
        ans++;
        continue;
      }
      set<char> rep;
      for (int i = 0; i < x.size(); i++) {
        if (chars.find(x[i]) != chars.end()) rep.insert(x[i]);
      }
      chars = rep;
    }
  }
  cout << max(0, ans - 1);
}
