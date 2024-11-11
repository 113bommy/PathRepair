#include <bits/stdc++.h>
using namespace std;
int N;
string s;
int main() {
  cin >> N;
  while (N--) {
    cin >> s;
    if (s == "::") {
      cout << "0000:0000:0000:0000:0000:0000:0000:0000" << endl;
      continue;
    }
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
      if (s[i] == ':') cnt++;
    if (s[0] == ':' && s[1] == ':' && cnt > 7) {
      s[0] = '0';
      s.insert(0, "000");
    }
    while (s.find("::") != string::npos && cnt < 7) {
      int p = int(s.find("::"));
      s.insert(p + 1, "0000:");
      cnt++;
    }
    if (s.find("::") != string::npos) {
      int p = int(s.find("::"));
      s.insert(p + 1, "0000");
    }
    s.push_back(':');
    for (int i = 0; i < 8; i++) {
      bool p;
      do {
        p = 0;
        for (int j = 5 * i; j < 5 * i + 4; j++)
          if (s[j] == ':') p = 1;
        if (p) s.insert(5 * i, "0");
      } while (p);
    }
    s.erase(39);
    cout << s << endl;
  }
  return 0;
}
