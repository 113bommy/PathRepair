#include <bits/stdc++.h>
using namespace std;
bool Normalize(string& str) {
  for (int i = 0; i + i < str.size(); ++i) {
    int j = str.size() - i - 1;
    if (str[i] == '?') {
      str[i] = str[j];
    }
    if (str[j] == '?') {
      str[j] = str[i];
    }
    if (str[i] != str[j]) {
      return false;
    }
  }
  return true;
}
string Fill(const string& str, int k) {
  vector<int> chk(k, 0);
  string res = str;
  for (int i = 0; i < str.size(); ++i) {
    if ('a' <= str[i] && str[i] - 'a' < k) {
      chk[str[i] - 'a'] = 1;
    }
  }
  stack<char> q;
  for (int i = 0; i < chk.size(); ++i) {
    if (chk[i]) continue;
    q.push(i + 'a');
  }
  char last = 'a';
  for (int i = (str.size() - 1) / 2; i >= 0; --i) {
    int j = str.size() - i - 1;
    if (res[i] == '?') {
      char tmp = last;
      if (!q.empty()) {
        tmp = q.top();
        q.pop();
      }
      res[i] = tmp;
      res[j] = tmp;
    }
  }
  return res;
}
int main() {
  int k;
  string str;
  while (cin >> k) {
    cin >> str;
    bool chk = Normalize(str);
    if (chk == false) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    str = Fill(str, k);
    chk = true;
    vector<int> t(k, 0);
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] < 'a' || str[i] - 'a' >= k) {
        chk = false;
        break;
      }
      t[str[i] - 'a'] = 1;
    }
    for (int i = 0; i < t.size(); ++i) {
      if (t[i] == 0) {
        chk = false;
        break;
      }
    }
    if (chk == false) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    cout << str << endl;
  }
  return 0;
}
