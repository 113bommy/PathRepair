#include <bits/stdc++.h>
using namespace std;
int n, m;
set<int> mySet;
string t[101];
char pat[101][40];
string finPat;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) cin >> t[i];
  int len = -1;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    x--;
    mySet.insert(x);
    if (len != -1 && (len != (int)t[x].length())) {
      cout << "No" << endl;
      return 0;
    } else
      len = t[x].length();
    for (int j = 0; j < len; j++) {
      if (t[x][j] >= 'a' && t[x][j] <= 'z')
        pat[j][t[x][j] - 'a']++;
      else if (t[x][j] == '.')
        pat[j][26]++;
      else
        pat[j][t[x][j] - '0' + 27]++;
    }
  }
  for (int i = 0; i < len; i++) {
    vector<int> vec;
    for (int j = 0; j < 37; j++)
      if (pat[i][j] != 0) vec.push_back(j);
    if ((int)vec.size() == 1) {
      if (vec[0] == 26)
        finPat += '.';
      else if (vec[0] < 26)
        finPat += (char)(vec[0] + 'a');
      else
        finPat += char(vec[0] + '0' - 27);
    } else
      finPat += '?';
  }
  for (int i = 0; i < n; i++) {
    if (mySet.count(i) || (int)t[i].length() != len) continue;
    bool isGood = true;
    for (int j = 0; j < len; j++) {
      if (finPat[j] == '?' || finPat[j] == t[i][j])
        continue;
      else
        isGood = false;
    }
    if (isGood) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  cout << finPat << endl;
  return 0;
}
