#include <bits/stdc++.h>
using namespace std;
string abbrevate(string word) {
  string result = word[0] + to_string(word.size() - 2) + word[word.size() - 1];
  return result;
}
int main() {
  int n;
  cin >> n;
  vector<string> r;
  for (int i = 0; i < n; i++) {
    string word;
    cin >> word;
    if (word.size() > 10) {
      r.push_back(abbrevate(word));
    } else {
      r.push_back(word);
    }
  }
  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << endl;
  }
  return 0;
}
