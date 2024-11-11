#include <bits/stdc++.h>
using namespace std;
string s;
map<char, char> mapping;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a = "bdopqvwxAHIMOTUVWXY";
  string b = "dboqpvwxAHIMOTUVWXY";
  for (int i = 0; i < (int)a.size(); i++) mapping[a[i]] = b[i];
  cin >> s;
  int mid = (int)s.size() / 2, sz = (int)s.size();
  for (int i = 0; i <= mid; i++)
    if (mapping.find(s[i]) == mapping.end() || mapping[s[i]] != s[sz - 1 - i]) {
      cout << "NIE" << endl;
      return 0;
    }
  cout << "TAK" << endl;
  return 0;
}
