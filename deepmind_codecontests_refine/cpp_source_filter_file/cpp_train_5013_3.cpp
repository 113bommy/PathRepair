#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    string e = "", o = "";
    vector<long long int> count(26, 0);
    for (long long int i = 0; i < s.size(); i++) count[s[i] - 'a']++;
    for (long long int i = 0; i < 26; i++) {
      while (count[i]--) {
        if ((s[i] - 'a') % 2 == 0)
          e += ('a' + i);
        else
          o += ('a' + i);
      }
    }
    if (e == "" || o == "") {
      cout << e << o << endl;
      continue;
    }
    if (abs(e[e.size() - 1] - o[0]) != 1) {
      cout << e << o << endl;
      continue;
    }
    if (abs(o[o.size() - 1] - e[0]) != 1) {
      cout << o << e << endl;
      continue;
    }
    cout << "No answer" << endl;
  }
  return 0;
}
