#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  cin >> c;
  string s;
  cin >> s;
  map<char, char> right;
  map<char, char> left;
  right.insert({'q', 'w'});
  right.insert({'w', 'e'});
  right.insert({'e', 'r'});
  right.insert({'r', 't'});
  right.insert({'t', 'y'});
  right.insert({'u', 'i'});
  right.insert({'i', 'o'});
  right.insert({'o', 'p'});
  right.insert({'a', 's'});
  right.insert({'s', 'd'});
  right.insert({'d', 'f'});
  right.insert({'f', 'g'});
  right.insert({'g', 'h'});
  right.insert({'h', 'j'});
  right.insert({'j', 'k'});
  right.insert({'l', ';'});
  right.insert({'z', 'x'});
  right.insert({'x', 'c'});
  right.insert({'c', 'v'});
  right.insert({'v', 'b'});
  right.insert({'b', 'n'});
  right.insert({'n', 'm'});
  right.insert({'m', ','});
  right.insert({',', '.'});
  right.insert({'n', 'm'});
  right.insert({'m', ','});
  right.insert({',', '.'});
  right.insert({'k', 'l'});
  left.insert({'w', 'q'});
  left.insert({'e', 'w'});
  left.insert({'r', 'e'});
  left.insert({'t', 'r'});
  left.insert({'d', 's'});
  left.insert({';', 'l'});
  left.insert({'y', 't'});
  left.insert({'f', 'd'});
  left.insert({'x', 'z'});
  left.insert({'u', 'y'});
  left.insert({'g', 'f'});
  left.insert({'c', 'x'});
  left.insert({'i', 'u'});
  left.insert({'h', 'g'});
  left.insert({'v', 'c'});
  left.insert({'o', 'i'});
  left.insert({'j', 'h'});
  left.insert({'b', 'v'});
  left.insert({'p', 'o'});
  left.insert({'k', 'j'});
  left.insert({'n', 'b'});
  left.insert({'s', 'a'});
  left.insert({'l', 'k'});
  left.insert({'m', 'n'});
  left.insert({',', 'm'});
  left.insert({'.', ','});
  left.insert({'/', '.'});
  if (c == 'R') {
    for (int i = 0; i < s.size(); i++) {
      char a = s[i];
      cout << left[a];
    }
  } else {
    for (int i = 0; i < s.size(); i++) {
      char a = s[i];
      cout << right[a];
    }
  }
  return 0;
}
