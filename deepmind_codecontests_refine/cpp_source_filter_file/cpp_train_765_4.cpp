#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> word;
  vector<set<int> > AtoZ;
  AtoZ.assign(26, set<int>());
  int n;
  cin >> n;
  string temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    temp += 'a' - 1;
    for (int j = 0; j < temp.size() - 1; j++) {
      AtoZ[temp.at(j) - 'a'].insert(temp.at(j + 1) - 'a');
    }
  }
  for (int i = 0; i <= 'z' - 'a'; i++) {
    if (AtoZ[i].empty()) {
      char ans = i + 'a';
      cout << ans;
      return 0;
    }
  }
  for (int i = 0; i < 'z' - 'a'; i++) {
    for (int j = 0; j < 'z' - 'a'; j++) {
      if (AtoZ[i].find(j) == AtoZ[i].end()) {
        char a1, a2;
        a1 = i + 'a';
        a2 = j + 'a';
        cout << a1 << a2 << endl;
        return 0;
      }
    }
  }
  return 0;
}
