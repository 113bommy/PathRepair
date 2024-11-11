#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string word;
    cin >> word;
    int prev;
    int distance = 0;
    for (int i = 0; i < s.size(); i++) {
      if (word[0] == s[i]) {
        prev = i;
        break;
      }
    }
    for (int i = 1; i < word.size(); i++) {
      for (int j = 0; j < s.size(); j++) {
        if (word[i] == s[j]) {
          distance += abs(prev - j);
          prev = j;
          break;
        }
      }
    }
    cout << distance << endl;
  }
}
