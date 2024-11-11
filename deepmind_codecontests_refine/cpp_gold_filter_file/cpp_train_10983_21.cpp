#include <bits/stdc++.h>
using namespace std;
int main() {
  int lc, uc = 0;
  string word;
  cin >> word;
  for (int i = 0; i < word.size(); i++) {
    if (int(word[i]) <= 90) {
      uc++;
    }
  }
  if (uc > word.size() / 2) {
    transform(word.begin(), word.end(), word.begin(), ::toupper);
  } else {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
  }
  cout << word;
  return 0;
}
