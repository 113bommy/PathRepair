#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  unordered_map<char, int> m;
  m.insert(pair<char, int>('A', 0));
  m.insert(pair<char, int>('B', 0));
  m.insert(pair<char, int>('C', 0));
  string s;
  for (int i = 0; i < 3; i++) {
    cin >> s;
    if (s[1] == '>')
      m[s[0]]++;
    else
      m[s[2]]++;
  }
  if (m['A'] == 1 && m['B'] == 1 && m['C'] == 1)
    cout << "Impossible";
  else {
    if (m['A'] == 0)
      cout << "A";
    else if (m['B'] == 0)
      cout << "B";
    else if (m['C'] == 0)
      cout << "C";
    if (m['A'] == 1)
      cout << "A";
    else if (m['B'] == 1)
      cout << "B";
    else if (m['C'] == 1)
      cout << "C";
    if (m['A'] == 2)
      cout << "A";
    else if (m['B'] == 2)
      cout << "B";
    else if (m['C'] == 2)
      cout << "C";
  }
  return 0;
}
