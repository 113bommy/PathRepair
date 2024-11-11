#include <bits/stdc++.h>
using namespace std;
string s1, s2;
vector<int> pos[101];
int main() {
  cin >> s1;
  cin >> s2;
  for (int i = 0; i < s1.size(); i++) {
    int t = s1[i] - 'a';
    pos[t].push_back(i);
  }
  int ans = 1, temp = -1;
  for (int i = 0; i < s2.size(); i++) {
    int t = s2[i] - 'a';
    if (pos[t].size() == 0) {
      printf("-1\n");
      return 0;
    }
    int newtemp =
        upper_bound(pos[t].begin(), pos[t].end(), temp) - pos[t].begin();
    if (newtemp >= pos[t].size()) {
      ans++;
      temp = -1;
      newtemp =
          upper_bound(pos[t].begin(), pos[t].end(), temp) - pos[t].begin();
    }
    temp = pos[t][newtemp];
  }
  cout << ans << endl;
  return 0;
}
