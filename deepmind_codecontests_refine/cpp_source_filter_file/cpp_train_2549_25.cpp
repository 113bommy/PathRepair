#include <bits/stdc++.h>
using namespace std;
char alphabets[27] = "abcdefghijklmnopqrstuvwxyz";
int main() {
  std::set<string> unique;
  string s;
  cin >> s;
  for (int i = 0; i < 26; ++i) {
    string newstr = s + alphabets[i];
    unique.insert(newstr);
    for (int j = newstr.length() - 1; j > 0; --j) {
      std::swap(newstr[j], newstr[j - 1]);
      unique.insert(newstr);
    }
  }
  cerr << unique.size() << endl;
  return 0;
}
