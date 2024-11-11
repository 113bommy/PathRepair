#include <bits/stdc++.h>
using namespace std;

int parse(const string& s, int i) {
  if (i < s.size() && s[i] == 'm') {
    i++;
    i = parse(s, i);
    if (s[i] != 'e') return i;
    i++;
    i = parse(s, i);
    if (s[i] != 'w') return i;
    i++;
  }
  return i;
}

int main() {
  string s;
  cin >> s;
  cout << (parse(s, 0) == s.size() ? "Cat" : "Rabbit") << endl;
  return 0;
}

