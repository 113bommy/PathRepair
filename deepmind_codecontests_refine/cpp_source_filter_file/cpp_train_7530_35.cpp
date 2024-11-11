#include <bits/stdc++.h>
using namespace std;
vector<int> a[26];
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  string s, res = "";
  cin >> s;
  for (int i = 0; i < int((s).size()); ++i) a[s[i] - 'a'].push_back(i);
  int ind = 0;
  for (int i = 25; i >= 0; --i) {
    for (int j = 0; j < int((a[i]).size()); ++j) {
      if (a[i][j] > ind) res += (char)('a' + i);
      ind = max(ind, a[i][j]);
    }
  }
  cout << res << endl;
  return 0;
}
