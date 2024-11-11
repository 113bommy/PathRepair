#include <bits/stdc++.h>
using namespace std;
void print(vector<char>& v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i];
  }
  cout << " ";
}
int main() {
  set<char> vol, used;
  long long num = 0;
  vol.insert('a');
  vol.insert('e');
  vol.insert('i');
  vol.insert('o');
  vol.insert('u');
  string s;
  cin >> s;
  vector<char> str;
  for (long long i = 0; i < s.size(); i++) {
    if (!vol.count(s[i])) {
      used.insert(s[i]);
      num++;
    } else {
      used.clear();
      num = 0;
    }
    if (num > 2 && used.size() > 1) {
      print(str);
      str.clear();
      used.clear();
      num = 1;
      used.insert(s[i]);
    }
    str.push_back(s[i]);
  }
  print(str);
}
