#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  vector<char> kq;
  cin >> s;
  int i = 0;
  while (i < s.size() - 2) {
    if (s.substr(i, 3) == "WUB") {
      if (kq.size() > 0)
        if (kq.back() != ' ') kq.push_back(' ');
      i = i + 2;
    } else
      kq.push_back(s[i]);
    i++;
  }
  for (int i = 0; i <= kq.size(); i++) cout << kq[i];
  return 0;
}
