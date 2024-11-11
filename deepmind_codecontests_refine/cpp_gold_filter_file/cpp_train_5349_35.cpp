#include <bits/stdc++.h>
using namespace std;
int main() {
  string word;
  cin >> word;
  string ans;
  if (word[0] > 'Z')
    word = char((word[0] - 'a') + 'A') + word.substr(1, word.length() - 1);
  cout << word << endl;
  return 0;
}
