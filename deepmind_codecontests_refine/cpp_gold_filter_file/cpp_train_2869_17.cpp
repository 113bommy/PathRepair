#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, t;
  cin >> t;
  for (i = 0; i < t; i++) {
    string word, word2;
    word2 = "";
    cin >> word;
    if (word.size() > 10) {
      int lastindex = word.size() - 1;
      word2 += word[0];
      word2 += to_string(word.size() - 2);
      word2 += word[lastindex];
      cout << word2 << endl;
    } else
      cout << word << endl;
  }
}
