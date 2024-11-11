#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int input() {
  string s;
  string news;
  int level = 0;
  int i = 0;
  string newnode;
  cin >> s;
  cin >> newnode;
  while (i < s.length() && s[i] == '&') {
    level--;
    i++;
  }
  while (i < s.length() && s[i] != '*') {
    news.push_back(s[i]);
    i++;
  }
  while (i < s.length()) {
    level++;
    i++;
  }
  if (!m.count(news)) {
    level -= 10000;
  }
  level += m[news];
  if (level < 0) level = -10000;
  if (!m.count(newnode)) {
    m.insert(pair<string, int>(newnode, level));
  } else {
    m[newnode] = level;
  }
  return 0;
}
int output() {
  string s, news;
  int i = 0;
  int level = 0;
  cin >> s;
  while (i < s.length() && s[i] == '&') {
    level--;
    i++;
  }
  while (i < s.length() && s[i] != '*') {
    news.push_back(s[i]);
    i++;
  }
  while (i < s.length()) {
    level++;
    i++;
  }
  if (m.count(news) && m[news] + level >= 0) {
    cout << "void";
    for (int j = 0; j < m[news] + level; j++) {
      cout << '*';
    }
    cout << endl;
  } else
    cout << "errtype" << endl;
  return 0;
}
int main() {
  int n;
  cin >> n;
  m.insert(pair<string, int>("void", 0));
  for (int i = 0; i < n; i++) {
    string cmd;
    cin >> cmd;
    if (cmd == "typedef") {
      input();
    } else {
      output();
    }
  }
  return 0;
}
