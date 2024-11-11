#include <bits/stdc++.h>
using namespace std;
string words[111111];
int main() {
  int n, x = 0;
  cin >> n;
  string s, ss;
  while (n--) {
    string tmp;
    cin >> tmp;
    s += "<3" + tmp;
    if (!n) s += "<3";
  }
  cin >> ss;
  for (int i = 0; i < (int)ss.size(); ++i)
    if (ss[i] == s[x]) x++;
  cout << (x + 1 == (int)ss.size() ? "yes" : "no");
}
