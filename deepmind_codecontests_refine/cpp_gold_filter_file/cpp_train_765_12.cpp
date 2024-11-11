#include <bits/stdc++.h>
using namespace std;
int main(int, char**) {
  int n;
  cin >> n;
  string s = "";
  string curr;
  for (int i = 0; i < n; ++i) {
    cin >> curr;
    s += ' ';
    s += curr;
  }
  queue<string> qs;
  qs.push("");
  string newS;
  while (true) {
    curr = qs.front();
    qs.pop();
    for (char c = 'a'; c <= 'z'; ++c) {
      newS = curr + c;
      if (s.find(newS) == string::npos) {
        cout << newS << endl;
        return 0;
      } else {
        qs.push(newS);
      }
    }
  }
  return 0;
}
