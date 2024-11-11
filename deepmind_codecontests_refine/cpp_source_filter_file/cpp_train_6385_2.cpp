#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string word, word2;
  cin >> word;
  for (int i = 1; i < n; ++i) {
    cin >> word2;
    word2.resize(word.size());
    if (word != word2) {
      if (word.size() == 0) {
        cout << '0';
        return 0;
      }
      word.resize((int)word.size() - 1);
      word2.resize(word.size());
    }
  }
  cout << word.size();
  return 0;
}
