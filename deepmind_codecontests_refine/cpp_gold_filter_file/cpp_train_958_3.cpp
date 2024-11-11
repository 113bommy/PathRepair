#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, ans;
  cin >> s >> ans;
  sort(s.begin(), s.end());
  int k = (int)s.rfind('0');
  if (k != -1 && k != s.size() - 1) {
    string w = s.substr(0, k + 1);
    s.erase(0, k + 1);
    s.insert(1, w);
  }
  if (s == ans)
    cout << "OK";
  else
    cout << "WRONG_ANSWER";
}
