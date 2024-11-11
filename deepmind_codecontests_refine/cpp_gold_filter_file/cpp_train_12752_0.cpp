#include <bits/stdc++.h>
using namespace std;
string s;
vector<string> top;
int ans;
void INPUT() {
  s = "+";
  string cur;
  cin >> cur;
  s += cur;
}
void OUTPUT() { cout << ans << endl; }
void count(string &x) {
  for (int i = 0; i < ((int)top.size()); i++)
    if (x == top[i]) ans++;
}
int main() {
  INPUT();
  string cur;
  for (int i = 1; i < ((int)s.size()); i++) {
    if (s[i] == ',') continue;
    if (s[i] == '.') {
      top.pop_back();
    } else if (s[i] == ':') {
      count(cur);
      top.push_back(cur);
    } else {
      if ((s[i - 1] < 'A') || (s[i - 1] > 'Z'))
        cur = s[i];
      else
        cur += s[i];
      if (s[i + 1] == '.') {
        count(cur);
        i++;
      }
    }
  }
  OUTPUT();
  return 0;
}
