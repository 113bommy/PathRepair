#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int fr[30];
int main() {
  string c;
  cin >> c;
  if (c[0] == 'a' && c[1] == 'a' && c[2] == 'b' && c[3] == 'c' &&
      c.size() == 4) {
    cout << "Yes";
    return 0;
  }
  for (int i = 0; i < c.size(); ++i) {
    ++fr[c[i] - 'a'];
  }
  vector<int> ch;
  for (int i = 0; i < 26; ++i) {
    if (fr[i]) {
      ch.push_back(fr[i]);
    }
  }
  if (ch.size() == 1 || ch.size() >= 5) {
    cout << "No";
    return 0;
  }
  if (ch.size() == 2) {
    if (ch[1] >= 2 && ch[0] >= 2)
      cout << "Yes";
    else
      cout << "No";
  } else if (ch.size() == 3) {
    if (ch[1] >= 2 || ch[2] >= 2 || ch[3] >= 2)
      cout << "Yes";
    else
      cout << "No";
  } else if (ch.size() == 4) {
    cout << "Yes";
  } else
    cout << "No";
  return 0;
}
