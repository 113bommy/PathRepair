#include <bits/stdc++.h>
using namespace std;
char color[6] = {'R', 'O', 'Y', 'G', 'B', 'V'};
vector<int> v;
int tedad[300];
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) tedad[s[i]]++;
  vector<int> v;
  for (int i = 0; i < 6; i++)
    if (tedad[color[i]]) v.push_back(tedad[color[i]]);
  sort(v.begin(), v.end());
  if (v.size() == 1)
    cout << 1 << endl;
  else if (v.size() == 2) {
    if (v[0] == 1)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  } else if (v.size() == 3) {
    if (v[0] == 1) {
      if (v[1] == 1)
        cout << 2 << endl;
      else
        cout << 3 << endl;
    } else
      cout << 6 << endl;
  } else if (v.size() == 4) {
    if (v[3] == 3)
      cout << 4 << endl;
    else if (v[3] == 2)
      cout << 8 << endl;
  } else if (v.size() == 5)
    cout << 15 << endl;
  else if (v.size() == 6)
    cout << 30 << endl;
  return 0;
}
