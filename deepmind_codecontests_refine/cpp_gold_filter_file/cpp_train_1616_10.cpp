#include <bits/stdc++.h>
using namespace std;
string s[100002];
int correct(string s) {
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') continue;
    if (s[i] != '1')
      return 0;
    else if (s[i] == '1')
      cnt++;
  }
  if (cnt > 1) return 0;
  return 1;
}
int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  int f = 0, idx = -1;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (!correct(s[i])) {
      idx = i;
      continue;
    }
    int cnt0 = 0, cnt1 = 0;
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '0')
        cnt0++;
      else if (s[i][j] == '1')
        cnt1++;
    }
    cnt += cnt0;
    if (cnt1 == 0) {
      f = 1;
    }
  }
  if (f)
    cout << "0\n";
  else {
    if (idx != -1)
      for (int i = 0; i < s[idx].size(); i++) {
        cout << s[idx][i];
      }
    else
      cout << "1";
    for (int i = 0; i < cnt; i++) {
      cout << "0";
    }
    cout << endl;
  }
  return 0;
}
