#include <bits/stdc++.h>
using namespace std;
int l;
string s;
char ret[100005];
bool f;
bool isOk(const string& s) {
  bool f = true;
  for (int i = 0; i < l / 2; ++i) {
    if (s[i] - '0' != 7) {
      if (s[i] - '0' > 7)
        return false;
      else
        return true;
    }
  }
  for (int i = l / 2; i < l; ++i) {
    if (s[i] - '0' != 4) {
      if (s[i] - '0' > 4)
        return false;
      else
        return true;
    }
  }
  return true;
}
void dfs(int pos, int four, bool big) {
  if (f || pos > l || four > l / 2 || pos - four > l / 2) {
    return;
  }
  if (pos == l) {
    ret[l] = '\0';
    cout << ret << endl;
    f = 1;
    return;
  }
  if (big) {
    for (int i = pos; i < l; ++i) {
      if (four < l / 2) {
        four++;
        ret[i] = '4';
      } else {
        ret[i] = '7';
      }
    }
    ret[l] = '\0';
    cout << ret << endl;
    f = 1;
    return;
  }
  if (s[pos] <= '4') {
    ret[pos] = '4';
    dfs(pos + 1, four + 1, s[pos] < '4');
  }
  if (s[pos] <= '7') {
    ret[pos] = '7';
    dfs(pos + 1, four + 1, s[pos] < '7');
  }
}
int main() {
  while (cin >> s) {
    l = s.length();
    f = 0;
    if (l % 2 == 1) {
      for (int i = 0; i < (l + 1) / 2; ++i) {
        cout << 4;
      }
      for (int i = (l + 1) / 2; i < l + 1; ++i) {
        cout << 7;
      }
      cout << endl;
    } else {
      if (isOk(s)) {
        dfs(0, 0, false);
      } else {
        for (int i = 0; i < (l + 2) / 2; ++i) {
          cout << 4;
        }
        for (int i = (l + 2) / 2; i < l + 2; ++i) {
          cout << 7;
        }
        cout << endl;
      }
    }
  }
}
