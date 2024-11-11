#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string word;
    cin >> word;
    int len = word.length();
    if (len > 10)
      cout << word.at(0) << len - 2 << word.at(len - 1) << endl;
    else
      cout << word << endl;
  }
  return 0;
}
