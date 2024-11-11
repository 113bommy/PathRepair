#include <bits/stdc++.h>
using namespace std;
bool mark[200];
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int maxx = 0;
  set<char> sett;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      for (int k = 0; k < 26; k++) mark[k] = 0;
      bool f = 0;
      int t = 0;
      for (int k = i; k < j; k++) {
        if (tolower(s[k]) != s[k]) f = 1;
        if (!mark[s[k] - 'a']) t++;
        mark[s[k] - 'a'] = 1;
      }
      if (f) continue;
      maxx = max(maxx, t);
    }
  }
  cout << maxx << endl;
}
