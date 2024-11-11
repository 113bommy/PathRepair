#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  {
    long long i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    string s;
    cin >> s;
    bool ch = 0;
    for (i = 0; i < s.size(); i++) {
      if (s[i] != '0' and s[i] != '.') {
        ch = 1;
      }
    }
    if (ch == 0) {
      cout << 0;
      return 0;
    }
    i = 0;
    while (i < s.size() and s[i] == '0') {
      i++;
    }
    s = s.substr(i);
    n = s.size();
    long long pos = -1;
    for (i = 0; i < n; i++) {
      if (s[i] == '.') {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      cout << s[0];
      string x = "";
      if (n > 1) {
        for (i = 1; i < n; i++) {
          x += s[i];
        }
        j = x.size();
        j--;
        while (j >= 0 and x[j] == '0') {
          j--;
        }
        if (j >= 0) {
          cout << '.';
          for (i = 0; i <= j; i++) {
            cout << x[i];
          }
        }
      }
      if (n > 1) cout << 'E' << n - 1;
      return 0;
    }
    j = n - 1;
    while (j > 0 and s[j] == '0') {
      j--;
    }
    n = j + 1;
    if (s[0] == '.') {
      for (i = 1; i < n; i++) {
        cnt++;
        if (s[i] != '0') {
          cout << s[i];
          i++;
          break;
        }
      }
      if (i < n) {
        cout << '.';
        for (; i < n; i++) {
          cout << s[i];
        }
      }
      cout << "E"
           << "-" << cnt;
      return 0;
    }
    i = 0;
    cout << s[i++];
    if (i < n) {
      for (; i < n; i++) {
        if (s[i] != '.') {
          cnt++;
        } else {
          break;
        }
      }
      string x = "";
      for (i = 1; i < n; i++) {
        if (s[i] != '.') {
          x += s[i];
        }
      }
      j = x.size();
      j--;
      while (j >= 0 and x[j] == '0') {
        j--;
      }
      if (j >= 0) {
        cout << '.';
        for (i = 0; i <= j; i++) {
          cout << x[i];
        }
      }
      if (cnt > 0) cout << "E" << cnt;
    }
  }
  return 0;
}
