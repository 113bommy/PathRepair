#include <bits/stdc++.h>
using namespace std;
int freq[10];
int dx[] = {1, -1};
void solve(string s) {
  memset(freq, 0, sizeof freq);
  int cp = 0, dp = 0;
  while (true) {
    if (isdigit(s[cp])) {
      freq[s[cp] - '0']++;
      cp += dx[dp];
      if (s[cp - dx[dp]] == '0') {
        s.erase(s.begin() + cp - dx[dp]);
        if (dp == 0) cp--;
      } else
        s[cp - dx[dp]]--;
    } else {
      if (s[cp] == '>')
        dp = 0;
      else
        dp = 1;
      cp += dx[dp];
      if (cp == s.size() || cp == -1) break;
      if (s[cp] == '>' || s[cp] == '<') {
        s.erase(s.begin() + cp - dx[dp]);
        if (dp == 0) cp--;
      }
    }
    if (cp == s.size() || cp == -1) break;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  while (q--) {
    int l, r;
    cin >> l >> r;
    solve(s.substr(l - 1, r - l + 1));
    for (int i = 0; i < 10; i++) cout << freq[i] << ' ';
    cout << '\n';
  }
  return 0;
}
