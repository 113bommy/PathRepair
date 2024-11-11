#include <bits/stdc++.h>
using namespace std;
int dxx[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dyy[] = {1, -1, 0, 0, -1, 1, 1, -1};
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  char k, c, r;
  map<char, int> m;
  int t = 3;
  while (t--) {
    cin >> k >> c >> r;
    if (c == '>')
      m[k]++;
    else
      m[r]++;
  }
  if (m['A'] == 2 && m['B'] == 1 && m['C'] == 0)
    cout << "CBA" << '\n';
  else if (m['B'] == 2 && m['A'] == 1 && m['C'] == 0)
    cout << "CAB" << '\n';
  else if (m['A'] == 0 && m['B'] == 1 && m['C'] == 2)
    cout << "ABC" << '\n';
  else if (m['A'] == 0 && m['B'] == 2 && m['C'] == 1)
    cout << "ACB" << '\n';
  else if (m['B'] == 0 && m['A'] == 1 && m['C'] == 2)
    cout << "BAC" << '\n';
  else if (m['B'] == 0 && m['C'] == 1 && m['A'] == 2)
    cout << "BCA" << '\n';
  else
    cout << "Impossible" << '\n';
}
