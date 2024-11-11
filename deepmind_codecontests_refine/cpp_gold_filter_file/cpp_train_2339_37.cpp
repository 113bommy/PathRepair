#include <bits/stdc++.h>
using namespace std;
string ss[] = {"rock", "paper", "scissors"};
map<string, int> mp;
int main() {
  string f, m, s;
  cin >> f >> m >> s;
  mp["rock"] = 0;
  mp["paper"] = 0;
  mp["scissors"] = 0;
  mp[f]++;
  mp[m]++;
  mp[s]++;
  if ((mp[ss[0]] == 3 || mp[ss[1]] == 3 || mp[ss[2]] == 3) ||
      (mp[ss[0]] == 1 && mp[ss[1]] == 1 && mp[ss[2]] == 1)) {
    cout << '?' << endl;
    return 0;
  }
  if (mp[ss[0]] == 2) {
    if (mp[ss[1]] == 1) {
      if (f == ss[1])
        cout << 'F' << endl;
      else if (m == ss[1])
        cout << 'M' << endl;
      else
        cout << 'S' << endl;
    } else
      cout << '?' << endl;
  } else if (mp[ss[1]] == 2) {
    if (mp[ss[2]] == 1) {
      if (f == ss[2])
        cout << 'F' << endl;
      else if (m == ss[2])
        cout << 'M' << endl;
      else
        cout << 'S' << endl;
    } else
      cout << '?' << endl;
  } else {
    if (mp[ss[0]] == 1) {
      if (f == ss[0])
        cout << 'F' << endl;
      else if (m == ss[0])
        cout << 'M' << endl;
      else
        cout << 'S' << endl;
    } else
      cout << '?' << endl;
  }
  return 0;
}
