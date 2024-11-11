#include <bits/stdc++.h>
using namespace std;
int n;
string w;
char t;
vector<string> forb;
bool mem[110];
string::iterator it;
string toL(string s) {
  for (int i = 0; i < (int)s.size(); i++) {
    s[i] = tolower(s[i]);
  }
  return s;
}
char isUpper(char s) { return s >= 'A' && s <= 'Z'; }
int main(void) {
  cin >> n;
  forb.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> forb[i];
  }
  cin >> w;
  cin >> t;
  memset(mem, 0, sizeof(mem));
  size_t found;
  string normal = toL(w);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < w.size(); j++) {
      if (normal.substr(j, forb[i].size()) == forb[i]) {
        for (int k = 0; k < forb[i].size(); k++) {
          mem[j + k] = true;
        }
      }
    }
  }
  for (int i = 0; i < w.size(); i++) {
    if (mem[i]) {
      if (tolower(w[i]) == tolower(t)) {
        char s = 'a';
        while (s == tolower(t)) s++;
        if (islower(w[i])) {
          w[i] = tolower(s);
        } else {
          w[i] = toupper(s);
        }
      } else {
        if (islower(w[i])) {
          w[i] = tolower(t);
        } else {
          w[i] = toupper(t);
        }
      }
    }
  }
  cout << w << endl;
  return 0;
}
