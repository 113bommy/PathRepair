#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a1, a2;
  cin >> a1 >> a2;
  string s, p;
  cin >> s >> p;
  int ns = s.size();
  int np = p.size();
  for (int i = 0; i < ns; i++) (s[i]) = char(s[i] - 32);
  for (int i = 0; i < np; i++) p[i] = ((p[i] == '1') ? 'T' : 'F');
  string answer = "";
  for (int i = 1; i <= (ns + np - 1); i++) {
    answer += '?';
  }
  for (int i = 0; i < np; i++) {
    if (p[i] == 'T') {
      for (int j = i; j < i + ns; j++) {
        if (answer[j] == '?') {
          answer[j] = s[j - i];
        } else {
          if (answer[j] == s[j - i]) {
          } else {
            cout << "No solution" << endl;
            return;
          }
        }
      }
    }
  }
  map<int, int> mp;
  for (int i = 0; i < (ns + np - 1); i++) {
    if (answer[i] == '?')
      answer[i] = 'A';
    else
      mp[i]++;
  }
  for (int i = 0; i < np; i++) {
    if (p[i] == 'F') {
      int check = 0;
      for (int j = i; j < i + ns; j++) {
        if (answer[j] != s[j - i]) check = 1;
      }
      if (check == 0) {
        int check1 = 0;
        for (int j = i + ns - 1; j >= i; j--) {
          if (mp[j] == 0) {
            for (int k = 0; k < 26; k++) {
              if (s[j - i] != (k + 65)) {
                answer[j] = (k + 65);
                check1 = 1;
                break;
              }
            }
            break;
          }
        }
        if (check1 == 0) {
          cout << "No solution" << endl;
          return;
        }
      }
    }
  }
  transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
  cout << answer << endl;
}
signed main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
