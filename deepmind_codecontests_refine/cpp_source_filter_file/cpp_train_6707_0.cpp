#include <bits/stdc++.h>
using namespace std;
int main() {
  string text;
  getline(cin, text);
  map<char, int> mapping;
  for (int i = 0; i < text.size(); i++) {
    mapping[text[i]]++;
  }
  int no_of_i = mapping['i'];
  while (no_of_i) {
    if ((mapping['n'] / 3 >= no_of_i ||
         mapping['n'] == 3 + (no_of_i - 1) * 2) &&
        mapping['e'] / 3 >= no_of_i && mapping['t'] >= no_of_i) {
      cout << no_of_i;
      return 0;
    }
    no_of_i--;
  }
  cout << 0;
  return 0;
}
