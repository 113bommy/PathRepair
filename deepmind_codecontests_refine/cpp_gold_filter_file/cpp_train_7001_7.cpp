#include <bits/stdc++.h>
using namespace std;
string s;
int n;
vector<int> present, possible;
string k = "abacaba";
bool check(int i, string ss) {
  bool ok = 1;
  for (int j = 0; j < 7; j++) {
    if (!(s[i + j] == k[j] || s[i + j] == '?')) {
      ok = 0;
      break;
    }
  }
  return ok;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    bool flag = 0;
    int cc = 0;
    for (int j = 0; j + 7 <= n; j++) {
      if (s.substr(j, 7) == k) cc++;
    }
    if (cc < 2) {
      for (int j = 0; j + 7 <= n; j++) {
        string ss = s;
        int cnt = 0;
        if (check(j, ss)) {
          for (int i = 0; i < 7; i++) ss[j + i] = k[i];
        }
        for (int i = max(j - 8, 0); i + 7 <= n; i++)
          if (ss.substr(i, 7) == k) cnt++;
        if (cnt == 1) {
          for (int i = 0; i < n; i++)
            if (ss[i] == '?') ss[i] = 'z';
          cout << "Yes\n";
          cout << ss << endl;
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0) {
      cout << "No\n";
    }
  }
}
