#include <bits/stdc++.h>
using namespace std;
string s;
vector<char> v;
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'h' && v.size() == 0) {
      v.push_back('h');
    }
    if (s[i] == 'e' && v.size() == 1) {
      v.push_back('e');
    }
    if (s[i] == 'i' && v.size() == 2 || v.size() == 4) {
      v.push_back('i');
    }
    if (s[i] == 'd' && v.size() == 3) {
      v.push_back('d');
    }
  }
  if (v.size() >= 5) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
