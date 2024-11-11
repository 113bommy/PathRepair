#include <bits/stdc++.h>
using namespace std;
deque<string> tree;
void f(string s) {
  s = s.substr(3);
  if (s[0] == '/') {
    tree.clear();
  }
  s += '/';
  string dir = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '/') {
      if (dir == "..") {
        tree.pop_back();
      } else if (dir != "") {
        tree.push_back(dir);
      }
      dir = "";
    } else {
      dir += s[i];
    }
  }
}
int main() {
  int n;
  cin >> n;
  string tmp;
  getline(cin, tmp);
  for (int i = 1; i <= n; i++) {
    getline(cin, tmp);
    if (tmp == "pwd") {
      for (auto it : tree) {
        cout << "/" << it;
      }
      cout << "/\n";
    } else {
      f(tmp);
    }
  }
}
