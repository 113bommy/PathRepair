#include <bits/stdc++.h>
using namespace std;
int main() {
  string t;
  cin >> t;
  int pos = -1;
  int num = 0;
  int len = t.length();
  for (int i = 0; i < len; ++i)
    if (t[i] == 'a') {
      pos = i;
      num++;
    }
  if (num == 0) {
    int now;
    if (len % 2 == 0) {
      now = len / 2;
      int flag = 1;
      for (int i = 0; i < len / 2; i++) {
        if (t[i] != t[now]) {
          flag = 0;
          break;
        }
        now++;
      }
      if (flag == 1) {
        for (int i = 0; i < len / 2; i++) cout << t[i];
        cout << endl;
        return 0;
      }
    }
    cout << ":(" << endl;
    return 0;
  }
  int l = (num + len) / 2;
  if (pos >= l || (num + len) % 2 == 1) {
    cout << ":(" << endl;
    return 0;
  }
  int j = l;
  for (int i = 0; i < l; i++) {
    if (t[i] == 'a') continue;
    if (t[i] != t[j]) {
      cout << ":(" << endl;
      return 0;
    }
    ++j;
  }
  for (int i = 0; i < l; i++) cout << t[i];
  cout << endl;
  return 0;
}
